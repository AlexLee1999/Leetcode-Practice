class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) {
            return image;
        }
        queue<pair<int, int>> myQueue;
        myQueue.push({sr, sc});
        int origin = image[sr][sc];
        image[sr][sc] = color;
        
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!myQueue.empty()) {
            pair<int, int> front = myQueue.front();
            myQueue.pop();
            
            for (int i=0; i<4; ++i) {
                int x = front.first + dirs[i][0];
                int y = front.second + dirs[i][1];
                if (x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] == origin) {
                    myQueue.push({x, y});
                    image[x][y] = color;
                }
            }
        }
        return image;
    }
};
// Time : O(n^2)
// Space : O(n^2)