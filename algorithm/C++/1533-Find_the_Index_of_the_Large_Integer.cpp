/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int left = 0;
        int right = reader.length() - 1;
        while (left <= right) {
            if (left == right) {
                return left;
            }
            int mid = left + (right - left) / 2;
            int result = 0;
            if ((right - left) & 1 != 0) {
                result = reader.compareSub(left, mid, mid + 1, right);
                if (result == 1) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                result = reader.compareSub(left, mid, mid, right);
                if (result == 1) {
                    right = mid - 1;
                } else if (result == -1) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
        }
        return -1;
    }
};
// Time : O(logn)
// Space : O(1)