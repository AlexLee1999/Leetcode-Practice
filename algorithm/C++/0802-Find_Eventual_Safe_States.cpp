class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edge(n, vector<int>());
        vector<int> indegree(n, 0);
        queue<int> myQueue;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            indegree[i] = graph[i].size();
            if (indegree[i] == 0) {
                myQueue.push(i);
            }
            for (int j = 0; j < graph[i].size(); ++j) {
                edge[graph[i][j]].push_back(i);
            }
        }
        while (!myQueue.empty()) {
            int front = myQueue.front();
            ans.push_back(front);
            myQueue.pop();
            for (int i=0; i<edge[front].size(); ++i) {
                int neighbor = edge[front][i];
                indegree[neighbor] --;
                if (indegree[neighbor] == 0) {
                    myQueue.push(neighbor);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)