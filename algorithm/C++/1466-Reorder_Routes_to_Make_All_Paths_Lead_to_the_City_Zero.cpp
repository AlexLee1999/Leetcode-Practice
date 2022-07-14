class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n, vector<int>());
        vector<vector<int>> reverse_edges(n, vector<int>());
        for (int i=0; i<connections.size(); ++i) {
            edges[connections[i][0]].push_back(connections[i][1]);
            reverse_edges[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        queue<int> myQueue;
        visited[0] = true;
        myQueue.push(0);
        int reverse = 0;
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            for (int i=0; i<edges[front].size(); ++i) {
                int neighbor = edges[front][i];
                if (visited[neighbor]) {
                    continue;
                }
                myQueue.push(neighbor);
                visited[neighbor] = true;
                reverse ++;
            }
            for (int i=0; i<reverse_edges[front].size(); ++i) {
                int neighbor = reverse_edges[front][i];
                if (visited[neighbor]) {
                    continue;
                }
                myQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
        return reverse;
    }
};
// Time : O(n)
// Space : O(E)
/* Idea : Do BFS from node 0, if the edge is in edges, then it need to be reversed (0->node) => (node->0)*/