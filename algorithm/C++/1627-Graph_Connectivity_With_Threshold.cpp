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
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU* mySet = new DSU(n + 1);
        vector<bool> ans;
        for (int i=threshold + 1; i<=n; ++i) {
            for (int j=2; i * j <=n; ++j) {
                mySet->join(i, i * j);
            }
            
        }
        for (int i=0; i<queries.size(); ++i) {
            ans.push_back(mySet->isConnected(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};
// Time : O(nlogn + Q)
// Space : O(n)