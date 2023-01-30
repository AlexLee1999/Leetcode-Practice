class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> edge(n, vector<int>());
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, visited, edge, hasApple);
    }
    int dfs(int node, vector<bool>& visited, vector<vector<int>>& edge, vector<bool>& hasApple) {
        int total = 0;
        visited[node] = true;
        for (int i=0; i<edge[node].size(); ++i) {
            if (!visited[edge[node][i]]) {
                total += dfs(edge[node][i], visited, edge, hasApple);
            }
        }
        if (node == 0) {
            return total;
        }
        if (hasApple[node] || total != 0) {
            return total + 2;
        }
        return 0;
    }
};