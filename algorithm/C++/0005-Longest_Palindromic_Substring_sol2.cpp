class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max = 0;
        string maxStr = "";
        bool table[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                table[i][j] = false;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                table[i][j] = ((s[i] == s[j]) && (j - i <= 2 || table[i+1][j-1]));
                if(table[i][j] == true && j - i + 1 > max){
                    max = j - i + 1;
                    maxStr = s.substr(i, max);
                }
            }
        }
        return maxStr;
    }
};
// Time : O(n^2)
// Space : O(n^2)
