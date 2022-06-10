class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> table(128, 0);
        for (int i=0; i<s.size(); ++i) {
            table[s[i]] ++;
        }
        int count = 0;
        bool single = false;
        for (int i=0; i<128; ++i) {
            if (table[i] >= 2) {
                if (table[i] & 1 == 1) {
                    single = true;
                }
                count += (table[i] / 2) * 2;
            } else if (table[i] == 1) {
                single = true;
            }
        }
        return single ? count + 1 : count;
    }
};
// Time : O(1)
// Space : O(128)