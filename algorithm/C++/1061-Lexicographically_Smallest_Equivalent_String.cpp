class DSU {
public: 
    DSU (int n) {
        parent = vector<int> (n, 0);
        rank = vector<int> (n, 0);
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool join(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return false;
        } else {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU* mySet = new DSU(26);
        
        for (int i=0; i<s1.size(); ++i) {
            mySet->join(s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for(int i=0; i<baseStr.size(); ++i) {
            int x = mySet->find(baseStr[i] - 'a');
            for (int j=0; j<26; ++j) {
                if (mySet->find(j) == x) {
                    res += (j + 'a');
                    break;
                }
            }
        }
        return res;
    }
};