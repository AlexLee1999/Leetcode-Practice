class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> first(n + 1, 0);
        vector<long long> second(n + 1, 0);
        for (int i=0; i<n; ++i) {
            second[i + 1] = second[i] + grid[1][i];
        }
        for (int i=n-1; i>=0; --i) {
            first[i] = first[i + 1] + grid[0][i];
        }
        long long result = LLONG_MAX;
        for (int i=0; i<=n - 1; ++i) {
            result = min(max(first[i + 1], second[i]), result);
        }
        return result;
    }
};