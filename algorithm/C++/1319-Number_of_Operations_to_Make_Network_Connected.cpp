class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int k = connections.size();
        if (k < n-1) {
            return -1;
        }
        vector<bool> visited(n, false);
        stack<int> myStack;
        vector<vector<int>> edge(n, vector<int>());
        for (int i=0; i<k; ++i) {
            edge[connections[i][0]].push_back(connections[i][1]);
            edge[connections[i][1]].push_back(connections[i][0]);
        }
        int cluster = 0;
        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                myStack.push(i);
                cluster ++;
                while (!myStack.empty()) {
                    int top = myStack.top();
                    myStack.pop();
                    visited[top] = true;
                    for (int i=0; i<edge[top].size(); ++i) {
                        if (!visited[edge[top][i]]) {
                            myStack.push(edge[top][i]);
                        }
                    }
                }
            }
        }
        return cluster - 1;
    }
};