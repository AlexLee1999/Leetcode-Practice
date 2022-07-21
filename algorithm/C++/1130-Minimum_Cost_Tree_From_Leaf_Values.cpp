class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        vector<vector<int>> max_subarray(n, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i) {
            int max_num = arr[i];
            max_subarray[i][i] = arr[i];
            for (int j=i + 1; j<n; ++j) {
                max_num = max(max_num, arr[j]);
                max_subarray[i][j] = max_num;
            }
        }
        for (int len = 1; len < n; ++len) {
            for (int start=0; start + len < n; ++start) {
                int end = start + len;
                int cost = INT_MAX;
                for (int k=start; k<end; ++k) {
                    // int max_left = *max_element(arr.begin() + start, arr.begin() + k + 1);
                    int max_left = max_subarray[start][k];
                    // int max_right = *max_element(arr.begin() + k + 1, arr.begin() + end + 1);
                    int max_right = max_subarray[k + 1][end];
                    cost = min(cost, table[start][k] + table[k + 1][end] + max_left * max_right);
                }
                table[start][end] = cost;
            }
        }
        return table[0][n - 1];
    }
};
// Time : O(n^3)
// Space : O(n^2)