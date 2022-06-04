class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> myMap;
        int left = 0;
        int right = 0;
        int len = 0;
        for (right=0; right < s.size(); ++right) {
            myMap[s[right]] ++;
            while (myMap.size() > 2) {
                myMap[s[left]] --;
                if (myMap[s[left]] == 0) {
                    myMap.erase(s[left]);
                }
                left ++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};