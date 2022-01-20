class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    island ++;
                    search(grid, visited, i, j);
                }
            }
        }
        return island; //DFS Solution
    }
    void search(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n || i < 0 || j < 0 || visited[i][j] || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        search(grid, visited, i+1, j);
        search(grid, visited, i, j+1);
        search(grid, visited, i-1, j);
        search(grid, visited, i, j-1);
    }
};