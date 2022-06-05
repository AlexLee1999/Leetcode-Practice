class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(s, 0, 0, "", ans);
        return ans;
    }
    void backtrack(string s, int index, int num, string cur, vector<string>& ans) {
        if (num == 4 && index >= s.size()) {
            ans.push_back(cur);
            return;
        }
        if (index >= s.size()) {
            return;
        }
        if (num == 4) {
            return;
        }
        for (int i=1; i<=min(3, (int)(s.size() - index)); ++i) {
            string sub_str = s.substr(index, i);
            if (stoi(sub_str) <= 255) {
                if (s[index] == '0' && stoi(sub_str) != 0) {
                    continue;
                }
                if (sub_str == "00" || sub_str == "000") {
                    continue;
                }
                string old_str = cur;
                if (num != 0) {
                   cur += "."; 
                }
                cur += s.substr(index, i);
                backtrack(s, index + i, num + 1, cur, ans);
                cur = old_str;
            }
        }
    }
};