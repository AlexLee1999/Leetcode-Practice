class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> myMap_s;
        unordered_map<char, int> myMap_t;
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int window_left = 0;
        int count = 0;
        for (int i=0; i < t.size(); ++i) {
            myMap_t[t[i]] ++;
        }
        for (right = 0; right < s.size(); ++right) {
            if(myMap_t.count(s[right]) != 0) {
                myMap_s[s[right]] ++;
                if (myMap_t[s[right]] == myMap_s[s[right]]) {
                    count ++;
                }
            }
            while (count == myMap_t.size()) {
                if (len > right - left + 1) {
                    len = right - left + 1;
                    window_left = left;
                }
                if (myMap_t.count(s[left]) != 0) {
                    
                    if (myMap_t[s[left]] == myMap_s[s[left]]) {
                        count --;
                    }
                    myMap_s[s[left]] --;
                }
                left ++;
            }
        }
        return len == INT_MAX ? "" : s.substr(window_left, len);
    }
};