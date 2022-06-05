class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> ans;
        backtrack(s, 0, cur, ans);
        return ans;
        
    }
    void backtrack(string& s, int start, vector<string>& cur, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(cur);
        }
        for (int i=start; i<s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i-start + 1));
                backtrack(s, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        while (end > start) {
            if (s[end] != s[start]) {
                return false;
            }
            end --;
            start ++;
        }
        return true;
    }
};