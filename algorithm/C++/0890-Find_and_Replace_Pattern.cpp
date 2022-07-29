class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (int i=0; i<words.size(); ++i) {
            if (isPattern(words[i], pattern)) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
    bool isPattern(string& a, string& b) {
        if (a.size() == 1 && b.size() == 1) {
            return true;
        }
        if (a.size() != b.size()) {
            return false;
        }
        unordered_map<char, char> myMap;
        unordered_map<char, char> myMap_inv; 
        for (int i=0; i<a.size(); ++i) {
            if (myMap.find(a[i]) == myMap.end() && myMap_inv.find(b[i]) == myMap_inv.end()) {
                myMap[a[i]] = b[i];
                myMap_inv[b[i]] = a[i];
            } else if (myMap.find(a[i]) == myMap.end() && myMap_inv.find(b[i]) != myMap_inv.end()) {
                return false;
            } else if (myMap.find(a[i]) != myMap.end() && myMap_inv.find(b[i]) == myMap_inv.end()) {
                return false;
            } else {
                if (myMap[a[i]] != b[i] || myMap_inv[b[i]] != a[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time : O(nk)
// Space : O(nk)