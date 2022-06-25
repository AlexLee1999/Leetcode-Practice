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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        DSU* mySet = new DSU(m * n);
        vector<pair<int, pair<int, int>>> edge;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<4; ++k) {
                    int x = dirs[k][0] + i;
                    int y = dirs[k][1] + j;
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        edge.push_back({abs(heights[x][y] - heights[i][j]), {x*n + y, i*n+j}});
                    }
                }
            }
        }
        sort(edge.begin(), edge.end());
        for (int i=0; i<edge.size(); ++i) {
            int a = edge[i].second.first;
            int b = edge[i].second.second;
            mySet->join(a, b);
            if (mySet->find(0) == mySet->find(m*n-1)) {
                return edge[i].first;
            }
        }
        return -1;
    }
};
// Time : O(mnlog(mn))
// Space : O(mn)