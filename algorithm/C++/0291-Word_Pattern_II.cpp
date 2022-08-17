class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> myMap;
        unordered_map<string, char> myMap_rev;
        return backtrack(pattern, s, myMap, myMap_rev, 0, 0);
    }
    
    bool backtrack(string& pattern, string& s, unordered_map<char, string>& myMap, unordered_map<string, char>& myMap_rev, int idx_pattern, int idx_s) {
        if (idx_s == s.size() && idx_pattern == pattern.size()) {
            return true;
        }
        if (idx_s >= s.size() || idx_pattern >= pattern.size()) {
            return false;
        }
        char ch = pattern[idx_pattern];
        for (int i=idx_s; i<s.size(); ++i) {
            string tmp = s.substr(idx_s, i-idx_s + 1);
            if (myMap.count(ch) && myMap[ch] == tmp && myMap_rev.count(tmp) && myMap_rev[tmp] == ch) {
                if (backtrack(pattern, s, myMap, myMap_rev, idx_pattern + 1, i + 1)) {
                    return true;
                }
            } else if (!myMap.count(ch) && !myMap_rev.count(tmp)){
                myMap[ch] = tmp;
                myMap_rev[tmp] = ch;
                if (backtrack(pattern, s, myMap, myMap_rev, idx_pattern + 1, i + 1)) {
                    return true;
                }
                myMap.erase(ch);
                myMap_rev.erase(tmp);
                
            }
        }
        return false;
    }
};
// Time : O(2^n)
// Space : O(2^n)