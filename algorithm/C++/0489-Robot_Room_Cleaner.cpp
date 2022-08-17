/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        unordered_set<string> mySet;
        backtrack(robot, 0, 0, mySet, dirs, 0);
    }
    void backtrack(Robot& robot, int row, int col, unordered_set<string>& mySet, vector<vector<int>>& dirs, int d) {
        robot.clean();
        mySet.insert(hashing(row, col));
        for (int i=0; i<4; ++i) {
            int new_d = (i + d) % 4;
            int x = row + dirs[new_d][0];
            int y = col + dirs[new_d][1];
            if (!mySet.count(hashing(x, y)) && robot.move()) {
                backtrack(robot, x, y, mySet, dirs, new_d);
                goBack(robot);
            }
            robot.turnRight();
        }
        
    }
    void goBack(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    string hashing(int row, int col) {
        return to_string(row) + "^"+ to_string(col);
    }
    
};