class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int right = 0;
        int len = 0;
        unordered_map<char, int> myMap;
        for (right = 0; right < s.size(); ++right) {
            myMap[s[right]] ++;
            while (myMap.size() > k) {
                myMap[s[left]] --;
                if (myMap[s[left]] == 0) {
                    myMap.erase(s[left]);
                }
                left ++;
            }
            len = max(len, right-left + 1);
        }
        return len;
    }
};