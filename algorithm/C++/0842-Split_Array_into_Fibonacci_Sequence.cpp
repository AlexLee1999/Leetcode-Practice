class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> cur;
        vector<int> ans;
        backtrack(cur, 0, num, ans);
        return ans;
    }
    void backtrack(vector<int>& cur, int idx, string& num, vector<int>& ans) {
        if (idx == num.size() && !cur.empty() && cur.size() > 2) {
            ans = cur;
            return;
        }
        if (num[idx] == '0') {
            int n = cur.size();
            if (n < 2) {
                cur.push_back(0);
                backtrack(cur, idx + 1, num, ans);
                cur.pop_back();
            } else if (cur[n - 1] + cur[n - 2] == 0) {
                cur.push_back(0);
                backtrack(cur, idx + 1, num, ans);
                cur.pop_back();
            }
        } else {
            for (int len=1; len <= min((int)num.size() - idx, 10); ++len) {
                string tmp = num.substr(idx, len);
                int n = cur.size();
                if (n < 2 && stoll(tmp) <= INT_MAX) {
                    cur.push_back(stoi(tmp));
                    backtrack(cur, idx + len, num, ans);
                    cur.pop_back();
                } else if (stoll(tmp) <= INT_MAX && (long long)cur[n - 1] + (long long)cur[n - 2] == stoi(tmp)) {
                    cur.push_back(stoi(tmp));
                    backtrack(cur, idx + len, num, ans);
                    cur.pop_back();
                }
            }
        }
    }
};
// Time : O(2^n)
// Space : O(n)