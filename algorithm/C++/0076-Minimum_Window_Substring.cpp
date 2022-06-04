class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> myMap;
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int window_left = 0;
        int count = t.size();
        for (int i=0; i < t.size(); ++i) {
            myMap[t[i]] ++;
        }
        for (right = 0; right < s.size(); ++right) {
            if (myMap[s[right]] > 0) {
                count --;
                
            }
            myMap[s[right]] --;
            if (count == 0) {
                while (left < right && myMap[s[left]] < 0) {
                    myMap[s[left]] ++;
                    left ++;
                }
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    window_left = left;
                }
                count ++;
                myMap[s[left]] ++;
                left ++;
            }
        }
        return len == INT_MAX ? "" : s.substr(window_left, len);
    }
};