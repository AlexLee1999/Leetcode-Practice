class Solution {
public:
    int longestSubstring(string s, int k) {
        int max_len = 0;
        for (int i=1; i<=26; ++i) {
            max_len = max(max_len, maxLen(s, k, i));
        }
        return max_len;
    }
    int maxLen(string s, int k, int n) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> myMap;
        int numUnique = 0;
        int overK = 0;
        int max_len = 0;
        for (right = 0; right < s.size(); ++right) {
            if (myMap[s[right]] == 0) {
                numUnique ++;
            }
            myMap[s[right]] ++;
            if (myMap[s[right]] == k) {
                overK ++;
            }
            while (numUnique > n) {
                if (myMap[s[left]] == k) {
                    overK --;
                }
                myMap[s[left]] --;
                if (myMap[s[left]] == 0) {
                    numUnique --;
                }
                left ++;
            }
            if (overK == n) {
                max_len = max(max_len, right - left + 1);
            }
        }
        return max_len;
    }
    
};
// Time : O(n)
// Space : O(n)