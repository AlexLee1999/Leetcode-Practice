class Solution {
public:
    bool checkPartitioning(string s) {
        vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));
        
        for (int i=0; i<s.size(); ++i) {
            for (int j=0; j<=i; ++j) {
                if (s[i] == s[j]) {
                    if (i - j <= 2 || table[j + 1][i - 1] == true) {
                        table[j][i] = true;
                    }
                }
            }
        }
        for (int i=1; i<s.size() - 1; ++i) { // First : s[0-j], Second : s[j + 1 - i], Third : s[i + 1, s.size() - 1]
            for (int j=0; j<i; ++j) {
                if (table[0][j] && table[j + 1][i] && table[i + 1][s.size() - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
// Time : O(n^2)
// Space : O(n^2)