class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> edge (colors.size(), vector<int>());
        vector<vector<int>> dp (colors.size(), vector<int>(26, 0));
        vector<int> indegree(colors.size(), 0);
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]] ++;
        }
        queue<int> myQueue;
        for (int i=0; i<indegree.size(); ++i) {
            if (indegree[i] == 0) {
                myQueue.push(i);
            }
        }
        int max_num = 0;
        int count = 0;
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            dp[front][colors[front] - 'a'] ++;
            count ++;
            max_num = max(max_num, dp[front][colors[front] - 'a']);
            for (int i=0; i<edge[front].size(); ++i) {
                for (int j=0; j<26; ++j) {
                    dp[edge[front][i]][j] = max(dp[edge[front][i]][j], dp[front][j]);
                }
                indegree[edge[front][i]] --;
                if(indegree[edge[front][i]] == 0) {
                    myQueue.push(edge[front][i]);
                }
            }
        }
        if (colors.size() != count) {
            return -1;
        }
        return max_num;
    }
};