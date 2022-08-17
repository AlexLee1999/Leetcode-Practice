class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> myMap;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] ++;
            if (myMap[s[i]] >= 2) {
                return s[i];
            }
        }
        return '\0';
    }
};
// Time : O(n)
// Space : O(n)