class DSU {
public:
    DSU(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i=0; i<parent.size(); ++i) {
            parent[i] = i;
        }
        num = n;
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
            num --;
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
    int numOfGroup() {
        return num;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int num;
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU* mySet = new DSU(n);
        for (int i=0; i<strs.size() - 1; ++i) {
            for (int j=i+1; j<strs.size(); ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    mySet->join(i, j);
                }
            }
        }
        return mySet->numOfGroup();
    }
    
    
    bool isSimilar(const string& a, const string& b) {
        int count = 0;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] != b[i]) {
                count ++;
            }
        }
        return count == 2 || count == 0;
    }
};
// Time : O(kn^2) k is the longest string size
// Space : O(n)