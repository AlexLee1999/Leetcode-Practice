class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current_result;
        backtrack(nums, 0, results, current_result);
        return results;
    }
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& results, vector<int>& current_result) {
        if (index == nums.size()) {
            results.push_back(current_result);
            return;
        }
        current_result.push_back(nums[index]);
        backtrack(nums, index + 1, results, current_result);
        current_result.pop_back();
        backtrack(nums, index + 1, results, current_result);
    }
};