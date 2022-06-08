class Solution {
public:
    int charToInt(char ch){
        return (ch - '0');
    }
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string s = "";

        vector<int> table(m+n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j<n; ++j) {
                int res = (charToInt(num1[i]) * charToInt(num2[j]));
                table[i+j] += res;
                table[i+j+1] += table[i+j] / 10;
                table[i+j] %= 10;
            }
        }
        for (const int& i: table) {
            s += to_string(i);
        }
        reverse(s.begin(), s.end());
        int i;
        for (i = 0; i < m + n; ++i) {
            if(s[i] != '0'){
                break;
            }
        }
        if (s.substr(i, m + n - i + 1) != "") {
            return s.substr(i, m + n - i + 1);
        }
        return "0";
    }
};
// Time : O(mn)
// Space : O(m + n)