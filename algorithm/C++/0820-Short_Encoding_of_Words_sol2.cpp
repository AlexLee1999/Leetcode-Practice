class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> mySet(words.begin(), words.end());
        for (int i=0; i<words.size(); ++i) {
            for (int j=1; j<words[i].size(); ++j) {
                mySet.erase(words[i].substr(j));
            }
        }
        int len = 0;
        for (auto it=mySet.begin(); it != mySet.end(); ++it) {
            len += it->size() + 1;
        }
        return len;
    }
};
// Time : O(n * l^2) l is the max length of words
// Space : O(n * l)