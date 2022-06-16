class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        unordered_set<string> mySet;
        for (int i = 0; i<words.size()-1; ++i) {
            for (int j = i + 1; j<words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    mySet.insert(words[i]);
                }
            }
        }
        return vector<string> {mySet.begin(), mySet.end()};
    }
};
// Time : O(n^2)
// Space : O(n)