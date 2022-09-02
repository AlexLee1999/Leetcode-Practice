class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size(), false);
        vector<vector<int>> edge(stones.size(), vector<int>());
        for (int i=0; i<stones.size(); ++i) {
            for (int j=i + 1; j<stones.size(); ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i=0; i<stones.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            queue<int> myQueue;
            myQueue.push(i);
            visited[i] = true;
            count ++;
            while (!myQueue.empty()) {
                int front = myQueue.front();
                myQueue.pop();
                for (int j=0; j<edge[front].size(); ++j) {
                    int neighbor = edge[front][j];
                    if (visited[neighbor]) {
                        continue;
                    }
                    visited[neighbor] = true;
                    myQueue.push(neighbor);
                }
            }
        }
        return stones.size() - count;
    }
};
// Time : O(n^2 + e)
// Space : O(n + e)