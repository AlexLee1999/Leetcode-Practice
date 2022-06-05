class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, ans);
        return ans;
    }
    void backtrack(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& ans) {
        ans.push_back(cur);
        for (int i=index; i<nums.size(); ++i) {
            if (i != index && nums[i] == nums[i-1]) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};