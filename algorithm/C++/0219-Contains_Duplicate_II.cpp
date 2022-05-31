class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> mySet;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.find(nums[i]) != mySet.end()) {
                return true;
            }
            mySet.insert(nums[i]);
            if (mySet.size() > k) {
                mySet.erase(nums[i-k]);
            }
        }
        return false;
    }
};