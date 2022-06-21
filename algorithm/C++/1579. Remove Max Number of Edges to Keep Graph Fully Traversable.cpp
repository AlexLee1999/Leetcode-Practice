class DSU {
public:
    DSU (int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i=0; i<n; ++i) {
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
            } else if (rank[rooty] > rank[rootx]) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU* mySet_A = new DSU(n + 1);
        DSU* mySet_B = new DSU(n + 1);
        int num = 0;
        for (int i=0; i<edges.size(); ++i) {
            if(edges[i][0] == 3) {
                num += (int)!mySet_A->join(edges[i][1], edges[i][2]);
                mySet_B->join(edges[i][1], edges[i][2]);
            }
        }
        for (int i=0; i<edges.size(); ++i) {
            if(edges[i][0] == 1) {
                num += (int)!mySet_A->join(edges[i][1], edges[i][2]);
            } else if (edges[i][0] == 2) {
                num += (int)!mySet_B->join(edges[i][1], edges[i][2]);
            }
        }
        return (mySet_A->isConnected() && mySet_B->isConnected()) ? num : -1;
    }
};
// Time : O(e) edge
// Space : O(n) nodes