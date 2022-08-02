class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int left = matrix[0][0];
        int right = matrix[m - 1][m - 1];
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int leftBound = left;
            int count = countLess(matrix, mid, leftBound);
            if (count == k) {
                return leftBound;
            } else if (count > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left; // If the number mid has less number larger than k, target = mid, therefore, return left
    }
    
    int countLess(vector<vector<int>>& matrix, int mid, int& leftBound) {
        int m = matrix.size();
        int row = m - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < m) {
            if (matrix[row][col] > mid) {
                row --;
            } else {
                leftBound = max(leftBound, matrix[row][col]);
                count += row + 1;
                col ++;
            }
        }
        return count;
    }
};
// Time : O(nlogW)
// Space : O(1)