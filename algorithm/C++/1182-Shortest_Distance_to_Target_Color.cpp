class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> myMap;
        vector<vector<int>> table(3, vector<int>(colors.size(), INT_MAX));
        vector<int> left(3, 0);
        vector<int> right(3, colors.size() - 1);
        for (int i=0; i<colors.size(); ++i) {
            int color = colors[i] - 1;
            for (int j = left[color]; j <= i; ++j) {
                table[color][j] = min(table[color][j], i - j);
            }
            left[color] = i + 1; // Use left to prune unnecessary search
        }
        for (int i=colors.size() - 1; i >= 0; --i) {
            int color = colors[i] - 1;
            for (int j = right[color]; j >= i; --j) {
                table[color][j] = min(table[color][j], j - i);
            }
            right[color] = i - 1; // Use right to prune unnecessary search
        }
        vector<int> ans (queries.size(), 0);
        for (int i=0; i<queries.size(); ++i) {
            ans[i] = table[queries[i][1] - 1][queries[i][0]] == INT_MAX ? -1 : table[queries[i][1] - 1][queries[i][0]];
        }
        return ans;
    }
};
// Time : O(N + Q)
// Space : O(N + Q)