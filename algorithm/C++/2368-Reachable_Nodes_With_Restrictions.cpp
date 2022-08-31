class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> restricted_set(restricted.begin(), restricted.end());
        vector<vector<int>> edge(n, vector<int>());
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 1;
        restricted_set.insert(0);
        dfs(0, edge, restricted_set, count);
        return count;
        
    }
    void dfs(int cur, vector<vector<int>>& edge, unordered_set<int>& restricted, int& count) {
        for (int i=0; i<edge[cur].size(); ++i) {
            int neighbor = edge[cur][i];
            if (!restricted.count(neighbor)) {
                count ++;
                restricted.insert(neighbor);
                dfs(neighbor, edge, restricted, count);
            }
        }
    }
};
// Time : O(n)
// Space : O(n)