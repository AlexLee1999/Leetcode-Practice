class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int j = 0;
        int maxNum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (map.find(s[i]) != map.end()) {
                j = max(j, map[s[i]] + 1);
            }
            if (maxNum < i - j + 1) {
                maxNum = i - j + 1;
            }
            map[s[i]] = i;
        }
        return maxNum;
    }
};
