class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> table (26, 0);
        if (m != n) {
            return false;
        }
        for (int i=0; i<m; ++i) {
            table[(int)s[i] - (int)'a']++;
            table[(int)t[i] - (int)'a']--;
        }
        for (int i=0; i<26; ++i) {
            if (table[i]!=0) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1)