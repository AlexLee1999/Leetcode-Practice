class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> myMap;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] ++;
        }
        for (int i=0; i<s.size(); ++i) {
            if (myMap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};