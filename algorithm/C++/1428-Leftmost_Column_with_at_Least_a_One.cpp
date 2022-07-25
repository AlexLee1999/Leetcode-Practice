/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int min_col = n;
        for (int i=0; i<m; ++i) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (binaryMatrix.get(i, mid) == 1) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            min_col = min(min_col, left);
        }
        return min_col == n ? -1 : min_col; // If min_col == n, then there is no 1 in the matrix
    }
};
// Time : O(nlogn)
// Space : O(1)