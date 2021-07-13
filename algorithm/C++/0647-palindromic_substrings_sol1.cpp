class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> table(n, vector<bool>(n, false));
        int count = 0;
        for (int i=n-1; i>=0; --i){
            for (int j=i; j<n; ++j){
                table[i][j] = ((s[i] == s[j]) && (j-i <= 2 || table[i+1][j-1]));
                count += (int)table[i][j];
            }
        }
        return count;
    }
};
