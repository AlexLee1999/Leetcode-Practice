class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string cur = "";
        vector<string> ans;
        backtrack(s, 0, cur, ans);
        return ans;
    }
    void backtrack(string& s, int idx, string& cur, vector<string>& ans) {
        if (cur.size() == s.size()) {
            ans.push_back(cur);
            return;
        }
        string old_cur = cur;
        if (isdigit(s[idx])) {
            cur += s[idx];
            backtrack(s, idx + 1, cur, ans);
            cur = old_cur;
        } else if (isupper(s[idx])){
            cur += s[idx];
            backtrack(s, idx + 1, cur, ans);
            cur = old_cur;
            cur += tolower(s[idx]);
            backtrack(s, idx + 1, cur, ans);
            cur = old_cur;
        } else {
            cur += s[idx];
            backtrack(s, idx + 1, cur, ans);
            cur = old_cur;
            cur += toupper(s[idx]);
            backtrack(s, idx + 1, cur, ans);
            cur = old_cur;
        }
    }
};