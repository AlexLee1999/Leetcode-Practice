class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp (n, false);
        unordered_set<string> table;
        for (int i=0; i<wordDict.size(); ++i) {
            table.insert(wordDict[i]);
        }
        for (int i=0; i<n; ++i) {
            for(int j=0; j<=i; j++) {
                string sub_str = s.substr(j, i-j + 1);
                if (table.find(sub_str) != table.end()) {
                    if (j == 0) {
                        dp[i] = true;
                    } else{
                        dp[i] = dp[i] || dp[j-1];
                    }
                }
            }
        }
        return dp[n-1];
    }
};