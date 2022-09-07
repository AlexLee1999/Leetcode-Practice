class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; ++i) {
            if (!check(matrix, i, true)) {
                return false;
            }
            if (!check(matrix, i, false)) {
                return false;
            }
        }
        return true;
    }
    bool check(vector<vector<int>>& matrix, int k, bool isRow) {
        int n = matrix.size();
        unordered_set<int> mySet;
        if (isRow) {
            for (int i=0; i<n; ++i) {
                if (!mySet.count(matrix[k][i]) && matrix[k][i] >= 1 && matrix[k][i] <= n) {
                    mySet.insert(matrix[k][i]);
                } else {
                    return false;
                }
            }
        } else {
            for (int i=0; i<n; ++i) {
                if (!mySet.count(matrix[i][k]) && matrix[i][k] >= 1 && matrix[i][k] <= n) {
                    mySet.insert(matrix[i][k]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time : O(n^2)
// Space : O(n^2)