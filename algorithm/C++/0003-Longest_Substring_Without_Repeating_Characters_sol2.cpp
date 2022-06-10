class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> myMap;
        int right = 0;
        int left = 0;
        int max_len = 0;
        for (right=0; right<s.size(); ++right) {
            myMap[s[right]] ++;
            while (myMap[s[right]] >= 2) {
                myMap[s[left]] --;
                left ++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
//Time : O(n)
//Space : O(min(m, n)) for hash table, m = char set size, n = string size