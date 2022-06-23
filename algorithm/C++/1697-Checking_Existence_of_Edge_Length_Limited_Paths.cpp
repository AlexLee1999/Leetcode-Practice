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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU* mySet = new DSU(n);
        vector<bool> ans(queries.size(), false);
        for (int i=0; i<queries.size(); ++i) {
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        int prev = 0;
        for (int i=0; i<queries.size(); ++i) {
            int left = prev;
            int right = edgeList.size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (edgeList[mid][2] < queries[i][2]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int idx = right;
            for (int j=prev; j<=right; ++j) {
                mySet->join(edgeList[j][0], edgeList[j][1]);
            }
            if (mySet->find(queries[i][0]) == mySet->find(queries[i][1])) {
                ans[queries[i][3]] = true;
            }
            prev = right + 1;
        }
        return ans;
    }
};
// Time : O(qlogq + nlogn)
// Space : O(n + q)