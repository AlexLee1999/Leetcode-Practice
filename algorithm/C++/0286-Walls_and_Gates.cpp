class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> myQueue;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i=0; i<rooms.size(); ++i) {
            for (int j=0; j<rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) {
                    myQueue.push({i, j});
                }
            }
        }
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> cell = myQueue.front();
                int x = cell.first;
                int y = cell.second;
                myQueue.pop();
                for (int j=0; j<dirs.size(); ++j) {
                    int x_new = x + dirs[j].first;
                    int y_new = y + dirs[j].second;
                    if (x_new >= 0 && y_new >= 0 && x_new < m && y_new < n && rooms[x_new][y_new] == 2147483647) {
                        myQueue.push({x_new, y_new});
                        rooms[x_new][y_new] = step + 1;
                    }
                }
            }
            step ++;
        }
    }
};