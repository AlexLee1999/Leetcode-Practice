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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU* mySet = new DSU(s.size());
        unordered_map<int, vector<char>> myMap;
        unordered_map<int, int> count;
        string res = "";
        for (int i=0; i<pairs.size(); ++i) {
            mySet->join(pairs[i][0], pairs[i][1]);
        }
        for (int i=0; i<s.size(); ++i) {
            myMap[mySet->find(i)].push_back(s[i]);
        }
        
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
        for (int i=0; i<s.size(); ++i) {
            res += myMap[mySet->find(i)][count[mySet->find(i)]];
            count[mySet->find(i)] ++;
        }
        return res;
    }
};
// Time : O((n + p) a(n) + nlogn)
// Space : O(n)