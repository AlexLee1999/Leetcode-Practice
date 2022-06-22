class DSU {
public:
    DSU(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i=0; i<parent.size(); ++i) {
            parent[i] = i;
        }
        edge = 0;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool join(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return false;
        } else {
            edge ++;
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rootx] = rooty;
                rank[rootx] ++;
            }
        }
        return true;
    }
    bool connected() {
        return edge == parent.size() - 1;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int edge;
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        DSU* mySet = new DSU(n + 1);
        int cost = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        for (int i=0; i<wells.size(); ++i) {
            myHeap.push({wells[i], {0, i + 1}});
        }
        for (int i=0; i<pipes.size(); ++i) {
            myHeap.push({pipes[i][2], {pipes[i][0], pipes[i][1]}});
        }
        
        while(!mySet->connected()) {
            if (mySet->join(myHeap.top().second.first, myHeap.top().second.second)) {
                cost += myHeap.top().first;
            }
            myHeap.pop();
        }
        return cost;
    }
};
// Time : ((w+p)logn) w = wells, p = pipes
// Space : O(n)