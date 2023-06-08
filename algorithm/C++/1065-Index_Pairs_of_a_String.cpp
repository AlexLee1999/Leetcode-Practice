class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_set<string> mySet(words.begin(), words.end());
        vector<vector<int>> ans;
        int n = text.size();
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                string substr = text.substr(i, j - i + 1);
                if (mySet.count(substr)) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};