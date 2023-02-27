/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, grid.size() - 1, 0, grid.size() - 1);
    }
    Node* dfs(vector<vector<int>>& grid, int row_s, int row_e, int col_s, int col_e) {
        if (row_s > row_e || col_s > col_e) {
            return nullptr;
        }
        int val = grid[row_s][col_s];
        bool flag = true;
        for (int r=row_s; r<=row_e; ++r) {
            for (int c=col_s; c<=col_e; ++c) {
                if (grid[r][c] != val) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            Node* node = new Node((bool)val, true);
            return node;
        }
        int row_m = (row_s + row_e) / 2;
        int col_m = (col_s + col_e) / 2;
        Node* upleft = dfs(grid, row_s, row_m, col_s, col_m);
        Node* downleft = dfs(grid, row_m + 1, row_e, col_s, col_m);
        Node* upright = dfs(grid, row_s, row_m, col_m + 1, col_e);
        Node* downright = dfs(grid, row_m + 1, row_e, col_m + 1, col_e);
        Node* node = new Node((bool)val, false, upleft, upright, downleft, downright);
        return node;
    }
};