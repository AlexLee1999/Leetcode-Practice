class DSU {
public:
    DSU(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i=0; i<parent.size(); ++i) {
            parent[i] = i;
        }
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

private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU* mySet = new DSU(n);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        
        for (int i=0; i<points.size(); ++i) {
            for (int j=i + 1; j<points.size(); ++j) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                myHeap.push({dis, {i, j}});
            }
        }
        int ans = 0;
        while (!myHeap.empty()) {
            pair<int, pair<int, int>> top = myHeap.top();
            myHeap.pop();
            if (mySet->join(top.second.first, top.second.second)) {
                ans += top.first;
            }
        }
        return ans;
    }
};
// Time : O(N^2logN)
// Space : O(N^2)