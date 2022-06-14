class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> myMap_st;
        unordered_map<char, char> myMap_ts;
        
        if (s.size() != t.size()) {
            return false;
        }
        for (int i=0; i<s.size(); ++i) {
            if ((myMap_st.find(s[i]) != myMap_st.end() && myMap_st[s[i]] != t[i]) || (myMap_ts.find(t[i]) != myMap_ts.end() && myMap_ts[t[i]] != s[i])) {
                return false;
            } else {
                myMap_st[s[i]] = t[i];
                myMap_ts[t[i]] = s[i];
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1) ASCII chars is fixed