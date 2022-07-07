class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> myQueue;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        myQueue.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '$';
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                if ((step != 0) && (front.first == 0 || front.second == 0 || front.first == m-1 || front.second == n-1)) {
                    return step;
                }
                for (int j=0; j<4; ++j) {
                    int x = front.first + dirs[j][0];
                    int y = front.second + dirs[j][1];
                    if (x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == '.') {
                        maze[x][y] = '$';
                        myQueue.push({x, y});
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