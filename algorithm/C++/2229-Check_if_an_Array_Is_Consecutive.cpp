class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int n = nums.size();
        int x = *min_element(nums.begin(), nums.end());
        unordered_set<int> mySet;
        for (int i=0; i<n; ++i) {
            if (nums[i] <= x + n - 1 && nums[i] >= x) {
                if (mySet.count(nums[i])) {
                    return false;
                }
                mySet.insert(nums[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(n)