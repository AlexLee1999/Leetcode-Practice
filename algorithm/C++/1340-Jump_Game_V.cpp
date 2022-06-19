class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> table(n, vector<int>(2, 1));
        vector<int> dp(n, 1);
        for (int i=0; i<n; ++i) {
            table[i][0] = arr[i];
            table[i][1] = i;
        }
        sort(table.begin(), table.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int max_num = 0;
        for (int i=0; i<table.size(); ++i) {
            int idx = table[i][1];
            for (int j=idx + 1; j <= min(n-1, idx + d); ++j) {
                if (arr[j] >= arr[idx]) {
                    break;
                } else {
                    dp[idx] = max(dp[idx], dp[j] + 1);
                }
            }
            for (int j=idx - 1; j >= max(0, idx - d); --j) {
                if (arr[j] >= arr[idx]) {
                    break;
                } else {
                    dp[idx] = max(dp[idx], dp[j] + 1);
                }
            }
            max_num = max(max_num, dp[idx]);
        }
        return max_num;
    }
};
// Time : O(nd)
// Space : O(n)