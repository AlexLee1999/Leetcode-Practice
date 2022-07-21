class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        unordered_map<string, int> myMap;
        int max_len = 1;
        for (int i=0; i<n; ++i) {
            myMap[words[i]] = 1;
            for (int j = 0; j<words[i].size(); ++j) {
                string predecessor = words[i].substr(0, j) + words[i].substr(j + 1);
                if (myMap.find(predecessor) != myMap.end()) {
                    myMap[words[i]] = max(myMap[words[i]], myMap[predecessor] + 1);
                    max_len = max(max_len, myMap[words[i]]);
                }
            }
        }
        return max_len;
    }
};
// Time : O(n)
// Space : O(n)