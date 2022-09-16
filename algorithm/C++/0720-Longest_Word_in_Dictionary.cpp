class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> mySet(words.begin(), words.end());
        sort(words.begin(), words.end(),[](string& a, string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() > b.size();
        });
        for (int i=0; i<words.size(); ++i) {
            if (isValid(words[i], mySet)) {
                return words[i];
            }
        }
        return "";
    }
    bool isValid(string word, unordered_set<string>& mySet) {
        string s = "";
        for (int i=0; i<word.size(); ++i) {
            s += word[i];
            if (!mySet.count(s)) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nlogn + W)
// Space : O(W)