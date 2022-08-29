class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, vector<int>> route;
        for (int i=0; i<routes.size(); ++i) {
            for (int j=0; j<routes[i].size(); ++j) {
                route[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> myQueue;
        myQueue.push(source);
        vector<bool> visited(routes.size(), false);
        int step = 1;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            
            for (int i=0; i<size; ++i) {
                int station = myQueue.front();
                myQueue.pop();
                for (int j=0; j<route[station].size(); ++j) {
                    int bus = route[station][j];
                    if (!visited[bus]) {
                        visited[bus] = 1;
                        for (int k=0; k<routes[bus].size(); ++k) {
                            int stop = routes[bus][k];
                            if (stop == target) {
                                return step;
                            }
                            myQueue.push(stop);
                        }
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(mn)
// Space : O(mn)