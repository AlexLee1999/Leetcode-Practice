class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> mySet;
        unordered_set<string> count;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.count(nums[i] - k)) {
                count.insert({to_string(nums[i] - k) + "_" + to_string(nums[i])});
            } 
            if (mySet.count(nums[i] + k)) {
                count.insert(to_string(nums[i]) + "_" + to_string(nums[i] + k));
            }
            mySet.insert(nums[i]);
        }
        return count.size();
    }
};