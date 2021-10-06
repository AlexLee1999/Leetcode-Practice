class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> mySet;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.find(nums[i]) != mySet.end()) {
                ans.push_back(nums[i]);
            }
            else {
                mySet.insert(nums[i]);
            }
        }
        return ans;
    }
};