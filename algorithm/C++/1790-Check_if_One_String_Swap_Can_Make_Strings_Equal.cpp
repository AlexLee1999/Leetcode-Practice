class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> count(26, 0);
        if (s1.size() != s2.size()) {
            return false;
        }
        for (int i=0; i<s1.size(); ++i) {
            count[s1[i] - 'a'] ++;
            count[s2[i] - 'a'] --;
        }
        for (int i=0; i<26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        int diff = 0;
        for (int i=0; i<s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff ++;
            }
            if (diff > 2) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1)