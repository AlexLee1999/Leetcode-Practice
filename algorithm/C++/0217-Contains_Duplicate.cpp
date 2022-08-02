class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.count(nums[i])) {
                return true;
            }
            else {
                mySet.insert(nums[i]);
            }
        }
        return false;
    }
};
// Time : O(n)
// Space : O(n)