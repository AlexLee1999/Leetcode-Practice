class DSU {
public:
    DSU(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i=0; i<parent.size(); ++i) {
            parent[i] = i;
        }
        count = 0;
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
            count ++;
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
    
    bool isConnected() {
        return count == parent.size() - 2;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        DSU* mySet = new DSU(n + 1);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        
        for (int i=0; i<connections.size(); ++i) {
            myHeap.push({connections[i][2], {connections[i][0], connections[i][1]}});
        }
        int ans = 0;
        for (int i=0; i<connections.size(); ++i) {
            pair<int, pair<int, int>> top = myHeap.top();
            myHeap.pop();
            if (mySet->join(top.second.first, top.second.second)) {
                ans += top.first;
            }
        }
        return mySet->isConnected() ? ans : -1;
    }
};