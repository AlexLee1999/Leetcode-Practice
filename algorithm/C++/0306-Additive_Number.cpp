class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> cur;
        return backtrack(cur, 0, num);
    }
    bool backtrack(vector<long long>& cur, int idx, string& num) {
        if (idx == num.size() && !cur.empty() && cur.size() > 2) {
            return true;
        }
        if (num[idx] == '0') {
            int n = cur.size();
            if (n < 2) {
                cur.push_back(0);
                if (backtrack(cur, idx + 1, num)) {
                    return true;
                }
                cur.pop_back();
            } else if (cur[n - 1] + cur[n - 2] == 0) {
                cur.push_back(0);
                if (backtrack(cur, idx + 1, num)) {
                    return true;
                }
                cur.pop_back();
            }
        } else {
            for (int len=1; len <= min((int)num.size() - idx, 18); ++len) {
                string tmp = num.substr(idx, len);
                int n = cur.size();
                if (n < 2) {
                    cur.push_back(stoll(tmp));
                    if (backtrack(cur, idx + len, num)) {
                        return true;
                    }
                    cur.pop_back();
                } else if (cur[n - 1] + cur[n - 2] == stoll(tmp)) {
                    cur.push_back(stoll(tmp));
                    if (backtrack(cur, idx + len, num)) {
                        return true;
                    }
                    cur.pop_back();
                }
            }
        }
        return false;
    }
};
// Time : O(2^N)
// Space : O(n)