class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        short m = nums1.size();
        short n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0;
        int right = m;
        while (left <= right) {
            int partition_x = (left + right) / 2;
            int partition_y = (m + n + 1) / 2 - partition_x;
            int left_x;
            int right_x;
            int left_y;
            int right_y;
            if (partition_x == 0) {
                left_x = INT_MIN;
            }
            else {
                left_x = nums1[partition_x - 1];
            }
            if (partition_x == m) {
                right_x = INT_MAX;
            }
            else {
                right_x = nums1[partition_x];
            }
            if (partition_y == 0){
                left_y = INT_MIN;
            }
            else {
                left_y = nums2[partition_y - 1];
            }
            if (partition_y == n){
                right_y = INT_MAX;
            }
            else {
                right_y = nums2[partition_y];
            }
            if (left_y <= right_x && left_x <= right_y) {
                if (((m + n) % 2) == 0) {
                    int res = max(left_x, left_y) + min(right_x, right_y);
                    return(res / 2.0);
                }
                else{
                    return (double)max(left_x, left_y);
                }

            }
            if (left_x > right_y) {
                right = partition_x - 1;
            }
            else {
                left = partition_x + 1;
            }
        }
        return -1;
    }
};
