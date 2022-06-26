class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> count(26, 0);
        vector<string> ans;
        for (int i=0; i<s.size(); ++i) {
            count[s[i] - 'a']++;
        }
        bool single = false;
        int single_idx = -1;
        for (int i=0; i<26; ++i) {
            if (((count[i] & 1) == 1) && !single) {
                single = true;
                single_idx = i;
            } else if (((count[i] & 1) == 1) && single) {
                return ans;
            }
        }
        string cur = "";
        if (single_idx != -1) {
            cur += char(single_idx + 'a');
            count[single_idx] --;
        }
        backtrack(count, cur, s, ans);
        return ans;
        
    }
    void backtrack(vector<int>& count, string cur, const string& s, vector<string>& ans) {
        if (cur.size() == s.size()) {
            ans.push_back(cur);
        }
        
        for (int i=0; i<26; ++i) {
            if (count[i] > 0) {
                count[i] -= 2;
                string old_cur = cur;
                cur += (char)(i + 'a');
                cur = (char)(i + 'a') + cur;
                backtrack(count, cur, s, ans);
                cur = old_cur;
                count[i] += 2;
            }
        }
    }
};
// Time : O(n/2!)
// Space : O(n)