class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (int i=0; i<n; ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> table(n, 0);
        int max_len = 0;
        for (int i=0; i<n; ++i) {
            table[i] = cuboids[i][2];
            for (int j=0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    table[i] = max(table[i], table[j] + cuboids[i][2]);
                }
            }
            max_len = max(max_len, table[i]);
        }
        return max_len;
    }
};
// Time : O(n^2)
// Space : O(n)