class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> table;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (table.find(nums[i]) != table.end()) {
                return true;
            }
            table.insert(nums[i]);
        }
        return false;
    }
};
