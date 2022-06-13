class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int max_sum = 0;
        unordered_set<int> mySet;
        for (right = 0; right < nums.size(); ++right) {
            while (left <= right && mySet.count(nums[right]) != 0) {
                sum -= nums[left];
                mySet.erase(nums[left]);
                left ++;
            }
            mySet.insert(nums[right]);
            sum += nums[right];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
// Time : O(n)
// Space : O(n)