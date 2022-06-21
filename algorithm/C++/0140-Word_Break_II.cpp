class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mySet;
        vector<string> arr;
        for (int i=0; i<wordDict.size(); ++i) {
            mySet.insert(wordDict[i]);
        }
        backtrack(s, wordDict, arr, "", 0, mySet);
        return arr;
        
    }
    void backtrack(string& s, vector<string>& wordDict, vector<string>& arr, string cur, int idx, unordered_set<string>& mySet) {
        if (idx == s.size()) {
            cur = cur.substr(0, cur.size() - 1);
            arr.push_back(cur);
            return;
        }
        for (int i=idx; i<s.size(); ++i) {
            if (mySet.count(s.substr(idx, i-idx+1))) {
                string old_cur = cur;
                cur += s.substr(idx, i-idx+1);
                cur += " ";
                backtrack(s, wordDict, arr, cur, i+1, mySet);
                cur = old_cur;
            }
        }
    }
};
// Time : O(2^N)
// Space : O(2^N)