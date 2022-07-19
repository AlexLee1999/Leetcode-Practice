class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int i=0; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                unordered_map<int, int> myMap;
                myMap[0] = 1;
                int cur = 0;
                for (int k=0; k<m; ++k) {
                    if (i > 0) {
                        cur += matrix[k][j];
                        cur -= matrix[k][i - 1];
                    } else {
                        cur += matrix[k][j];
                    }
                    res += myMap[cur - target];
                    myMap[cur] ++;
                }
            }
        }
        return res;
    }
};
// Time : O(n^2m)
// Space : O(n^2m)