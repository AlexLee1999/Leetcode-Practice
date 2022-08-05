class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> seq;
        for (int i=0; i<n; ++i) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end()) {
                seq.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            left[i] = seq.size();
        }
        seq.clear();
        for (int i=n - 1; i>=0; --i) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end()) {
                seq.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            right[n - 1 - i] = seq.size();
        }
        int max_len = 0;
        for (int i=0; i<n; ++i) {
            if (right[n - i - 1] > 1 && left[i] > 1) {
                max_len = max(max_len, right[n - 1 - i] + left[i] - 1);
            }
        }
        return nums.size() - max_len;
    }
};
// Time : O(nlogn)
// Space : O(n)