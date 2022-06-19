class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid - 1;
            } else if (arr[mid] <= arr[mid + 1]) {
                left = mid + 1;
            }
        }
        return left;
    }
};
// Time : O(logn)
// Space : O(1)