class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> mySet;
        if (s.size() < k) {
            return false;
        }
        for (int i=0; i<=s.size()-k; ++i) {
            mySet.insert(s.substr(i, k));
        }
        return mySet.size() == (1 << k);
    }
};