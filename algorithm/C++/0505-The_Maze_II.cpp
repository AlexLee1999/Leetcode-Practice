class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, pair<int, int>>> myQueue;
        myQueue.push({0, {start[0], start[1]}});
        distance[start[0]][start[1]] = 0;
        while (!myQueue.empty()) {
            pair<int, pair<int, int>> front = myQueue.front();
            myQueue.pop();
            for (int i=0; i<4; ++i) {
                int x = front.second.first + dirs[i][0];
                int y = front.second.second + dirs[i][1];
                int count = 1;
                while (x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == 0) {
                    x += dirs[i][0];
                    y += dirs[i][1];
                    count ++;
                } 
                x -= dirs[i][0];
                y -= dirs[i][1]; //backwards to the place maze[x][y] == 0
                count --;
                if (distance[front.second.first][front.second.second] + count < distance[x][y]) {
                    distance[x][y] = distance[front.second.first][front.second.second] + count;
                    myQueue.push({distance[x][y], {x, y}});
                }
            }
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1: distance[destination[0]][destination[1]];
    }
};
// Time : O(mn)
// Space : O(mn)