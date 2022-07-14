class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all_visited = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> myQueue;
        vector<vector<bool>> visited(n, vector<bool>(1<<n, false));
        for (int i=0; i<n; ++i) {
            myQueue.push({i, {0, 1<<i}});
            visited[i][1 << i] == true;
        }
        while (!myQueue.empty()) {
            int cur_node = myQueue.front().first;
            int dist = myQueue.front().second.first;
            int mask = myQueue.front().second.second;
            myQueue.pop();
            if (mask == all_visited) {
                return dist;
            }
            for (int i=0; i<graph[cur_node].size(); ++i) {
                int neighbor = graph[cur_node][i];
                int next_mask = mask | (1 << neighbor);
                int next_dist = dist + 1;
                if (!visited[neighbor][next_mask]) {
                    myQueue.push({neighbor, {next_dist, next_mask}});
                    visited[neighbor][next_mask] = true;
                }
            }
        }
        return -1;
    }
};
// Time : O(n^2 * 2^n)
// Space : O(n * 2^n)