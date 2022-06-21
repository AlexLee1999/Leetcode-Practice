class DSU {
public:
    DSU(int n) {
        parent = vector<int>(n + 1, 0);
        rank = vector<int>(n + 1, 0);
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
            } else if (rank[y] > rank[x]) {
                parent[rootx] = rooty;
            } else {
                parent[rootx] = rooty;
                rank[rooty] ++; 
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* mySet = new DSU(n);
        for (int i=0; i<n; ++i) {
            if (!mySet->join(edges[i][0], edges[i][1])) {
                return edges[i];
            } 
        }
        return vector<int>{-1, -1};
    }
};
// Time : O(Na(N))
// Space : O(N)