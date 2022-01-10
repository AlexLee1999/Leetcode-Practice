class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        backtrack(nums, results, 0);
        return results;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& results, int index) {
        if (index == nums.size()) {
            results.push_back(nums);
        }
        for (int i=index; i<nums.size(); ++i) {
            swap(nums[index], nums[i]);
            backtrack(nums, results, index+1);
            swap(nums[index], nums[i]);
        }
    }
};