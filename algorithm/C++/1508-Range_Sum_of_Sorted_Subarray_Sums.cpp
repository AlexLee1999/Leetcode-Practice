class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans(n * (n + 1) / 2, 0);
        vector<int> prefix(n + 1, 0);
        int ptr = 0;
        int mod = 1e9 + 7;
        for (int i=0; i<n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                ans[ptr] = (prefix[j + 1] - prefix[i]);
                ptr ++;
            }
        }
        sort(ans.begin(), ans.end());
        int count = 0;
        for (int i=left - 1; i<=right - 1; ++i) {
            count = (count + ans[i]) % mod;
        }
        return count;
    }
};
// Time : O(n^2logn)
// Space : O(n^2)