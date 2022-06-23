class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edge(n);
        for (int i=0; i<connections.size(); ++i) {
            edge[connections[i][0]].push_back(connections[i][1]);
            edge[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> disc(n);
        vector<int> min(n);
        vector<vector<int>> bridges;
        vector<bool> visited(n, false);
        dfs(0, -1, edge, disc, min, bridges, visited, 1);
        return bridges;
    }
    void dfs(int node, int parent, const vector<vector<int>>& edge, vector<int>& disc, vector<int>& mintime, vector<vector<int>>& bridges, vector<bool>& visited, int level) {
        disc[node] = level;
        mintime[node] = level;
        level ++;
        visited[node] = true;
        for (int i=0; i<edge[node].size(); ++i) {
            if (edge[node][i] == parent) {
                continue; // prevent back edges
            }
            if (!visited[edge[node][i]]) {
                dfs(edge[node][i], node, edge, disc, mintime, bridges, visited, level); //first check child node
            }
            mintime[node] = min(mintime[edge[node][i]], mintime[node]); // update mintime to reachable nodes
            if (disc[node] < mintime[edge[node][i]]) {
                bridges.push_back({node, edge[node][i]});
            }
        }
    }
};
//Tarjan's algorithm 