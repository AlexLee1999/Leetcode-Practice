class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> cur;
        backtrack(nums, cur, ans, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void backtrack(vector<int>& nums, vector<int>& cur, set<vector<int>>& ans, int idx) {
        if (cur.size() >= 2) {
            ans.insert(cur);
        }
        for (int i=idx; i<nums.size(); ++i) {
            if (cur.empty() || nums[i] >= cur.back()) {
                cur.push_back(nums[i]);
                backtrack(nums, cur, ans, i + 1);
                cur.pop_back();
            }
        }
    }
};
// Time : O(n2^n)
// Space : O(n^2)