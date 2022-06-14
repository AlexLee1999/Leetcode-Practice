class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        string s = "";
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; j++) {
                if (str1[i] == str2[j]) {
                    table[i+1][j+1] = table[i][j] + 1;
                } else {
                    table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
                }
            }
        }
        int str1_ptr = m-1;
        int str2_ptr = n-1;
        while (str1_ptr >= 0 && str2_ptr >= 0) {
            if (str1[str1_ptr] == str2[str2_ptr]) {
                s += str1[str1_ptr];
                str1_ptr --;
                str2_ptr --;
            } else {
                if (table[str1_ptr + 1][str2_ptr] >= table[str1_ptr][str2_ptr + 1]) {
                    s += str2[str2_ptr];
                    str2_ptr --;
                } else {
                    s += str1[str1_ptr];
                    str1_ptr --;
                }
            }
            
        }
        while (str1_ptr >= 0) {
            s += str1[str1_ptr];
            str1_ptr --;
        }
        while (str2_ptr >= 0) {
            s += str2[str2_ptr];
            str2_ptr --;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// Time : O(mn)
// Space : O(mn)