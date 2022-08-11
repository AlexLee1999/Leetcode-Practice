class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left <= right) {
            int left_bound = left;
            int mid = left + (right - left) / 2;
            int count = countLess(m, n, mid, left_bound);
            if (count == k) {
                return left_bound;
            } else if (count > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int countLess(int m, int n, int mid, int& left_bound) {
        int col = 1;
        int row = m;
        int count = 0;
        while (col <= n && row > 0) {
            if (col * row > mid) {
                row --;
            } else {
                left_bound = max(left_bound, row * col);
                count += (row);
                col ++;
            }
        }
        return count;
    }
};
// Time : O((m + n)log(mn))
// Space : O(1)