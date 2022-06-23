class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return vector<int>{0};
        }
        vector<vector<int>> edge(n, vector<int>());
        vector<int> indegree(n, 0);
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]] ++;
            indegree[edges[i][1]] ++;
        }
        
        queue<int> myQueue;
        for (int i=0; i<n; ++i) {
            if (indegree[i] == 1) { // Leaf
                myQueue.push(i);
            }
        }
        vector<int> ans;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            ans.clear();
            for (int i=0; i<size; ++i) {
                int front = myQueue.front();
                myQueue.pop();
                ans.push_back(front);
                for (int j=0; j<edge[front].size(); ++j) {
                    indegree[edge[front][j]] --;
                    if (indegree[edge[front][j]] == 1) {
                        myQueue.push(edge[front][j]);
                    }
                }
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)