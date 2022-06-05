class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> ans;
        backtrack(n, 2, cur, ans);
        return ans;
    }
    void backtrack(int n, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (n <= 1) {
            if (cur.size() > 1) {
                ans.push_back(cur);
            }
            return;
        }
        for (int i=start; i*i<=n; ++i) {
            if (n % i == 0) {
                cur.push_back(i);
                backtrack(n/i, i, cur, ans);
                cur.pop_back();
            }
        }
    }
};