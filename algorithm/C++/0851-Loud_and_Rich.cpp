class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, 0);
        vector<int> indegree(n, 0);
        vector<vector<int>> edges(n, vector<int>());
        queue<int> myQueue;
        for (int i=0; i<richer.size(); ++i) {
            edges[richer[i][0]].push_back(richer[i][1]);
            indegree[richer[i][1]] ++;
        }
        for (int i=0; i<n; ++i) {
            if (indegree[i] == 0) {
                myQueue.push(i);
            }
            ans[i] = i;
        }
        
        while (!myQueue.empty()) {
            int cur = myQueue.front();
            myQueue.pop();
            for (int i=0; i<edges[cur].size(); ++i) {
                int neighbor = edges[cur][i];
                indegree[neighbor] --;
                if (indegree[neighbor] == 0) {
                    myQueue.push(neighbor);
                }
                if (quiet[ans[neighbor]] > quiet[ans[cur]]) {
                    ans[neighbor] = ans[cur];
                }
            }
        }
        return ans;
    }
};
// Time : O(V+E)
// Space : O(V + E)