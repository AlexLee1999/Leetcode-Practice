class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> table(n + 1, vector<double>(target + 1, 0));
        table[0][0] = 1.0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=target; ++j) {
                if (j > 0) {
                    table[i + 1][j] = table[i][j - 1] * prob[i] + table[i][j] * (1 - prob[i]);
                } else {
                    table[i + 1][j] = table[i][j] * (1 - prob[i]);
                }
            }
        }
        return table[n][target];
    }
};
// Time : O(nT)
// Space : O(nT)