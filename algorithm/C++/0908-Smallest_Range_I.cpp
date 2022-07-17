class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(), nums.end());
        int min_num = *min_element(nums.begin(), nums.end());
        return max(max_num - min_num - 2 * k, 0);
    }
};
// Time : O(n)
// Space : O(n)