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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for (int i=0; i<edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<int> critical;
        vector<int> pseudo;
        int optimal = MST(n, edges, -1, -1);
        for (int i=0; i<edges.size(); ++i) {
            int ex = MST(n, edges, -1, i);
            if (ex > optimal) {
                critical.push_back(edges[i][3]);
            } else {
                int inc = MST(n, edges, i, -1);
                if (inc == optimal) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }
        return vector<vector<int>>{critical, pseudo};
        
        
    }
    int MST(int n, vector<vector<int>>& edges, int include, int exclude) {
        DSU* mySet = new DSU(n);
        int count = 0;
        int cost = 0;
        if (include != -1) {
            mySet->join(edges[include][0], edges[include][1]);
            count ++;
            cost += edges[include][2];
        }
        for (int i=0; i<edges.size(); ++i) {
            if (i == exclude) {
                continue;
            } else {
                if (mySet->find(edges[i][0]) != mySet->find(edges[i][1])) {
                    mySet->join(edges[i][0], edges[i][1]);
                    count ++;
                    cost += edges[i][2];
                }
            }
        }
        return count == n - 1 ? cost : INT_MAX;
    }
};
// Time : O(eloge + e^2)
// Space : O(n)