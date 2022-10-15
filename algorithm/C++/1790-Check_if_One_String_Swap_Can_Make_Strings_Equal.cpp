class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        char a = '\0';
        char b = '\0';
        bool needSwap = false;
        bool swaped = false;
        for (int i=0; i<s1.size(); ++i) {
            if (s1[i] != s2[i] && !needSwap) {
                a = s1[i];
                b = s2[i];
                needSwap = true;
            } else if (s1[i] != s2[i] && needSwap && !swaped) {
                if (a != s2[i] || b != s1[i]) {
                    return false;
                }
                swaped = true;
            } else if (s1[i] != s2[i] && swaped) {
                return false;
            }
        }
        if (needSwap && !swaped) {
            return false;
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1)