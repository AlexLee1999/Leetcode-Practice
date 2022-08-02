class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for (int i=0; i<accounts.size(); ++i) {
            int total = 0;
            for (int j=0; j<accounts[i].size(); ++j) {
                total += accounts[i][j];
            }
            max_wealth = max(max_wealth, total);
        }
        return max_wealth;
    }
};
// Time : O(nk)
// Space : O(1)