class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int len=3; len<=n; ++len) {
            for (int start=0; start <= n-len; ++start){
                int end = start + len - 1;
                if (len == 3) {
                    table[start][end] = values[start] * values[start + 1] * values[end];
                } else {
                    table[start][end] = INT_MAX;
                    for (int k=start + 1; k<end; ++k) {
                        table[start][end] = min(table[start][end], table[start][k] + values[start] * values[k] * values[end] + table[k][end]);
                    }
                }
            }
        }
        return table[0][n - 1];
    }
};
// Time : O(n^2)
// Space : O(n^2)