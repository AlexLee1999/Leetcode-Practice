class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        set<int> mySet(arr2.begin(), arr2.end());
        vector<vector<int>> table(n + 1, vector<int>(n + 1, INT_MAX));
        table[0][0] = INT_MIN;
        for (int j=1; j<=n; ++j) {//dp[i][j] = the min number with i operations and end with index j
            for (int i=0; i<=j; ++i) {
                if (table[i][j - 1] < arr1[j - 1]) {
                    table[i][j] = arr1[j - 1];
                }
                if (i > 0) {
                    auto it = mySet.upper_bound(table[i - 1][j - 1]);
                    if (it != mySet.end()) {
                        table[i][j] = min(table[i][j], *it);
                    }
                }
                if (j == n && table[i][j] != INT_MAX) {
                    return i;
                }
            }
        }
        return -1;
    }
};
// Time : O(n^2logm)
// Space : O(n)