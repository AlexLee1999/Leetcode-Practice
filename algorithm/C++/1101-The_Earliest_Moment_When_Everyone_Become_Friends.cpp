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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU* mySet = new DSU(n);
        int count = n;
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i=0; i<logs.size(); ++i) {
            if (mySet->join(logs[i][1], logs[i][2])) {
                count--;
            }
            if (count == 1) {
                return logs[i][0];
            }
        }
        return -1;
        
    }
};