class Solution {
public:
    void dfs(int n, vector<int>& edges, vector<bool>& visited, int& count) {
        count ++;
        visited[n] = true;
        if (edges[n] != -1 && !visited[edges[n]]) {
            dfs(edges[n], edges, visited, count);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> in_degree(n, 0);
        for (int i=0; i<n; ++i) {
            if (edges[i] == -1) {
                continue;
            }
            in_degree[edges[i]] ++;
        }
        queue<int> myQueue;
        for (int i=0; i<n; ++i) {
            if (in_degree[i] == 0) {
                myQueue.push(i);
            }
        }
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            if (edges[front] == -1) {
                continue;
            }
            in_degree[edges[front]] --;
            if (in_degree[edges[front]] == 0) {
                myQueue.push(edges[front]);
            }
        }
        vector<bool> visited (n, false);
        int ans = -1;
        for (int i=0; i<n; ++i) {
            if (visited[i] == false && in_degree[i] > 0) {
                int count = 0;
                dfs(i, edges, visited, count);
                ans = max(ans, count);
            }
        }
        return ans;        
    }
};