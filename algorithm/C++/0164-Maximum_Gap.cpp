class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        if (max_val == min_val) {
            return 0;
        }
        int bucket_size = max(1, (int)(max_val - min_val) / ((int)nums.size() - 1));
        int bucket_num = (max_val - min_val) / bucket_size + 1;
        vector<pair<int, int>> buckets(bucket_num, {INT_MAX, INT_MIN});
        for (int i=0; i<nums.size(); ++i) {
            int idx = (nums[i] - min_val) / bucket_size;
            buckets[idx].first = min(buckets[idx].first, nums[i]);
            buckets[idx].second = max(buckets[idx].second, nums[i]);
        }
        int prev_max = min_val;
        int max_gap = 0;
        for (int i=0; i<bucket_num; ++i) {
            if (buckets[i].first == INT_MAX) {
                continue;
            }
            max_gap = max(max_gap, buckets[i].first - prev_max);
            prev_max = buckets[i].second;
        }
        return max_gap;
    }
};
// Time : O(n + b)
// Space : O(b)