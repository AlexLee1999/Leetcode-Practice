class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> table(26, 0);
        for (int i=0; i<s.size(); ++i) {
            table[s[i] - 'a'] ++;
        }
        for (int i=0; i<t.size(); ++i) {
            if (table[t[i] - 'a'] == 0) {
                return t[i];
            }
            table[t[i] - 'a'] --;
        }
        return '\0';
    }
};
// Time : O(n)
// Space : O(1)