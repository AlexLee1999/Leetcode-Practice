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
    bool equationsPossible(vector<string>& equations) {
        DSU* mySet = new DSU(26);
        for (int i=0; i<equations.size(); ++i) {
            if (equations[i][1] == '='){
                mySet->join(equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        for (int i=0; i<equations.size(); ++i) {
            if (equations[i][1] == '!'){
                if (mySet->find(equations[i][0]-'a') == mySet->find(equations[i][3]-'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};