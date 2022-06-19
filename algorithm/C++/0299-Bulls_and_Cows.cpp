class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> table_s(10, 0);
        vector<int> table_g(10, 0);
        int A = 0;
        int B = 0;
        for (int i=0; i<secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                A++;
            } else {
                table_s[secret[i] - '0'] ++;
                table_g[guess[i] - '0'] ++;
            }
        }
        for (int i=0; i<10; ++i) {
            B += min(table_s[i], table_g[i]);
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};
// Time : O(n)
// Space : O(1)