class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> ans;
        backtrack(n, cur, ans);
        return ans;
    }
    void backtrack(int n, vector<int>& cur, vector<vector<int>>& ans) {
        int start;
        if (cur.empty()) {
            start = 2;
        } else {
            start = cur.back();
        }
        for (int i=start; i*i<=n; ++i) {
            if (n % i == 0) {
                cur.push_back(i);
                cur.push_back(n/i);
                ans.push_back(cur);
                cur.pop_back();
                backtrack(n/i, cur, ans);
                cur.pop_back();
            }
        }
    }
};