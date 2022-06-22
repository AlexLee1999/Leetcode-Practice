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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> myMap;
        vector<vector<string>> res;
        DSU* mySet = new DSU(n);
        for (int i=0; i<accounts.size(); ++i) {
            for (int j = 1; j<accounts[i].size(); ++j) {
                if (myMap.find(accounts[i][j]) == myMap.end()) {
                    myMap[accounts[i][j]] = i;
                } else {
                    mySet->join(myMap[accounts[i][j]], i);
                }
            }
        }
        unordered_map<int, vector<string>> catagorize;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            catagorize[mySet->find(it->second)].push_back(it->first);
        }
        for (auto it = catagorize.begin(); it != catagorize.end(); ++it) {
            vector<string> tmp = {accounts[it->first][0]};
            for (int i=0; i<it->second.size(); ++i) {
                tmp.push_back(it->second[i]);
            }
            sort(tmp.begin() + 1, tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};
// Time : O(NKlogNK) (sorting) N num of accounts k = max length of accounts
// Space : O(NK)