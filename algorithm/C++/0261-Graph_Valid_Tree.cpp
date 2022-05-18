class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n, vector<int>(0, 0));
        for (int i=0; i<edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        stack<int> myStack;
        myStack.push(0);
        while(!myStack.empty()) {
            int node = myStack.top();
            if (visited[node]) {
                return false;
            }
            visited[node] = true;
            myStack.pop();
            for (int i=0; i<adj[node].size(); ++i) {
                int adj_node = adj[node][i];
                myStack.push(adj_node);
                auto it = find(adj[adj_node].begin(), adj[adj_node].end(), node);
                if (it != adj[adj_node].end()) {
                    adj[adj_node].erase(it);
                }
            }
        }
        for (int i=0; i<visited.size(); ++i) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};