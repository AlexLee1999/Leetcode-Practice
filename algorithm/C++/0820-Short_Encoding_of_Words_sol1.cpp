class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        string s = "";
        for (int i=0; i<words.size(); ++i) {
            string cur = words[i] + '#';
            if (s.find(cur) == string::npos) {
                s += cur;
            }
        }
        return s.size();
    }
};
// Time : O(n^2) W is the sum of char of words
// Space : O(W)