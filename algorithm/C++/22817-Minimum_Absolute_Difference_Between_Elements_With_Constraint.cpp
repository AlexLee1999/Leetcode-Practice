class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> mySet;
        int difference = INT_MAX;
        for (int i=x; i<nums.size(); ++i) {
            mySet.insert(nums[i - x]);
            auto it = mySet.upper_bound(nums[i]);
            if (it != mySet.end()) {
                difference = min(difference, abs(*it - nums[i]));
            }
            if (it != mySet.begin()) {
                difference = min(difference, abs(*prev(it) - nums[i]));
            }
        }
        return difference;
    }
};