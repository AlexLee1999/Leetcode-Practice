class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> myQueue;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int num = 0;
        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                num ++;
                myQueue.push(i);
                visited[i] = true;
                while (!myQueue.empty()) {
                    int front = myQueue.front();
                    myQueue.pop();
                    for (int j=0; j<n; ++j) {
                        if (isConnected[front][j] == 1 && !visited[j]) {
                            myQueue.push(j);
                            visited[j] = true;
                        } 
                    }
                }
            }
        }
        return num;
    }
};
// Time : O(n^2)
// Space : O(n)