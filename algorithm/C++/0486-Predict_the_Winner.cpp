class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; --i) {
            for (int j=i; j<n; ++j) {
                if (i == j) {
                    table[i][j] = nums[i];
                } else {
                    table[i][j] = max(nums[i] - table[i + 1][j], nums[j] - table[i][j - 1]);
                }
            }
        }
        return table[0][n-1] >= 0;
    }
};
// Time : O(n^2)
// Space : O(n^2)