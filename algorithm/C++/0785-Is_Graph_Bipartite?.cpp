class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> level(n, -1);
        queue<int> myQueue;
        for (int k=0; k<n; ++k) {
            if (level[k] == -1) {
                myQueue.push(k);
                int step = 0;
                level[k] = 0;
                while (!myQueue.empty()) {
                    int size = myQueue.size();
                    for (int j=0; j<size; ++j) {
                        int front = myQueue.front();
                        myQueue.pop();
                        for (int i=0; i<graph[front].size(); ++i) {
                            if (level[graph[front][i]] == -1) {
                                level[graph[front][i]] = step + 1;
                                myQueue.push(graph[front][i]);
                            } else {
                                if ((level[graph[front][i]] & 1) == (level[front] & 1)) {
                                    return false;
                                } 
                            }
                        }   
                    }
                    step ++;
                }
            }
        }
        return true;
    }
};