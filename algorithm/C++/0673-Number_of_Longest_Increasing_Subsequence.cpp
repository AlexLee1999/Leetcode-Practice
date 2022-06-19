class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> freq(n, 1);
        for (int i=1; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        freq[i] = freq[j];
                        dp[i] = max(dp[i], dp[j] + 1);
                    } else if (dp[i] == dp[j] + 1){
                        freq[i] += freq[j];
                    }
                    
                }
            }
        }
        int max = *max_element(dp.begin(), dp.end());
        int num = 0;
        for (int i=0; i<dp.size(); ++i) {
            if (dp[i] == max) {
                num += freq[i];
            }
        }
        return num;
    }
};
// Time : O(n^2)
// Space : O(n)