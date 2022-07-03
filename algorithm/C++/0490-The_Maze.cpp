class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> myQueue;
        myQueue.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while (!myQueue.empty()) {
            pair<int, int> front = myQueue.front();
            myQueue.pop();
            if (front.first == destination[0] && front.second == destination[1]) {
                return true;
            }
            for (int i=0; i<4; ++i) {
                int x = front.first + dirs[i][0];
                int y = front.second + dirs[i][1];
                while (x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == 0) {
                    x += dirs[i][0];
                    y += dirs[i][1];
                } 
                x -= dirs[i][0];
                y -= dirs[i][1]; //backwards to the place maze[x][y] == 0
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    myQueue.push({x, y});
                }
            }
        }
        return false;
    }
};
// Time : O(mn)
// Space : O(mn)