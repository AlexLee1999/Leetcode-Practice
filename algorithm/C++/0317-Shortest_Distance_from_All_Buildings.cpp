class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int house_count = 0;
        int min_dis = INT_MAX;
        int empty_value = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> distance(m, vector<int>(n, 0));
        for (int i=0; i<grid.size(); ++i) {
            for (int j = 0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) { // Do BFS from every house
                    min_dis = INT_MAX;
                    house_count ++;
                    queue<pair<int, int>> myQueue;
                    myQueue.push({i, j});
                    int step = 0;
                    while (!myQueue.empty()) {
                        int size = myQueue.size();
                        for (int l=0; l<size; ++l) {
                            pair<int, int> front = myQueue.front();
                            myQueue.pop();
                            for (int k=0; k<4; ++k) {
                                int x = front.first + dirs[k][0];
                                int y = front.second + dirs[k][1];
                                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == empty_value) {
                                    myQueue.push({x, y});
                                    grid[x][y] --;
                                    distance[x][y] += (step + 1);
                                    min_dis = min(min_dis, distance[x][y]);
                                }
                            }
                        }
                        step ++;
                    }
                    empty_value --;
                }
            }
        }
        return min_dis == INT_MAX ? -1 : min_dis;
    }
};
// Time : O(mn)
// Space : O(mn)