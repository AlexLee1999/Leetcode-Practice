class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<int> mySet;
        vector<int> degree(n, 0);
        int max_rank = 0;
        for (int i=0; i<roads.size(); ++i) {
            mySet.insert(roads[i][0] * 10000 + roads[i][1]);
            mySet.insert(roads[i][1] * 10000 + roads[i][0]);
            degree[roads[i][0]] ++;
            degree[roads[i][1]] ++;
        }
        for (int i=0; i<n - 1 ; ++i) {
            for (int j=i + 1; j < n; ++j) {
                if (mySet.count(i * 10000 + j) != 0 || mySet.count(j * 10000 + i) != 0) {
                    max_rank = max(max_rank, degree[i] + degree[j] - 1);
                } else {
                    max_rank = max(max_rank, degree[i] + degree[j]);
                }
            }
        }
        return max_rank;
    }
};
// Time : O(n^2)
// Space : O(n)