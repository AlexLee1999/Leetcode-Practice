class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col = n-1;
        int row = 0;
        while(row<m && col>=0){
            if(matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};
