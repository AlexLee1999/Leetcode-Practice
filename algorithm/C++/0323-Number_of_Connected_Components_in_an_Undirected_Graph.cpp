class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n, vector<int>{});
        for (int i=0; i<edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        queue<int> myQueue;
        int result = 0;
        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                myQueue.push(i);
                result ++;
                visited[i] = true;
                while (!myQueue.empty()) {
                    int front = myQueue.front();
                    myQueue.pop();
                    for (int j=0; j<adj[front].size(); ++j) {
                        if (!visited[adj[front][j]]) {
                            myQueue.push(adj[front][j]);
                            visited[adj[front][j]] = true;
                        }
                    }
                }
            }
        }
        return result;
    }
};