enum Color {WHITE, GRAY, BLACK};
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> edge(n);
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
        }
        vector<Color> visited(n, WHITE);
        return dfs(n, edge, destination, source, visited);
    }
    bool dfs(int n, vector<vector<int>>& edge, int d, int node, vector<Color>& visited) {
        if (node == d && edge[node].empty()) {
            return true;
        }
        if (node != d && edge[node].empty()) {
            return false;
        }
        if (visited[node] == GRAY) {
            return false;
        }
        visited[node] = GRAY;
        for(int i=0; i<edge[node].size(); ++i) {
            if (!dfs(n, edge, d, edge[node][i], visited)) {
                return false;
            }
        }
        visited[node] = BLACK;
        return true;
    }
};
// Time : O(V + E)
// Space : O(V + E)