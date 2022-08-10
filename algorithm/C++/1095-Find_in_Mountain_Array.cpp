/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                right = mid - 1;
            } 
        }
        int peak = left;
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        left = peak;
        right = mountainArr.length() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) < target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
// Time : O(logn)
// Space : O(1)