class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> edge(bombs.size(), vector<int>());
        
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                double dis = sqrt(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2));
                if (dis <= bombs[i][2]) {
                    edge[i].push_back(j);
                }
                if (dis <= bombs[j][2]) {
                    edge[j].push_back(i);
                }
            }
        }
        int max_num = 0;
        queue<int> myQueue;
        for (int i=0; i<n; ++i) {
            vector<bool> visited(n, false);
            myQueue.push(i);
            visited[i] = true;
            int num = 0;
            while(!myQueue.empty()) {
                int front = myQueue.front();
                myQueue.pop();
                num ++;
                for (int j = 0; j<edge[front].size(); ++j) {
                    if (!visited[edge[front][j]]) {
                        visited[edge[front][j]] = true;
                        myQueue.push(edge[front][j]);
                    }
                }
            }
            max_num = max(max_num, num);
        }
        return max_num;
    }
};
// Time : O(n^2)
// Space : O(n)