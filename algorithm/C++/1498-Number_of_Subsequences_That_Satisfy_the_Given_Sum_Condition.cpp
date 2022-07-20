class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        int mod = 1e9 + 7;
        vector<int> pow_table(n, 1);
        for (int i=1; i<n; ++i) {
            pow_table[i] = (pow_table[i - 1] * 2) % mod;
        }
        int j = n - 1;
        int i = 0;
        while (j >= i) {
            if (nums[i] + nums[j] <= target) {
                count = (count + pow_table[j-i]) % mod;
                // Here, the subarray arr[i~j] is valid if arr[i] is in the subarray(min = arr[i], max <= arr[j])
                // So, there are 2^(j - i) possibilities (arr[i + 1~j])
                i ++;
            } else {
                j --;
            }
        }
        return count % mod;
    }
};
// Time : O(n)
// Space : O(n)