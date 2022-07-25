class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i=0; i<n; ++i) {
            totalSum += nums[i];
        }
        if (totalSum & 1 == 1) {
            return false;
        } 
        int targetSum = totalSum >> 1;
        
        vector<vector<bool>> table(n + 1, vector<bool>(targetSum + 1));
        
        table[0][0] = true;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=targetSum; ++j) {
                if (j >= nums[i - 1]) {
                    table[i][j] = table[i - 1][j] || table[i - 1][j - nums[i - 1]];
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        return table[n][targetSum];
    }
};
// Time : O(nT)
// Space : O(nT)