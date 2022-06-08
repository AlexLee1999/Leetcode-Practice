class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1); // assume nums1 is smaller
        }
        
        int left = 0;
        int right = m; //do binary search in nums1
        // Find the cut in nums1, which can be found in 0~m
        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            int left1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            int left2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            int right1 = (cut1 == m ? INT_MAX : nums1[cut1]);
            int right2 = (cut2 == n ? INT_MAX : nums2[cut2]);
            if (left1 <= right2 && left2 <= right1) {
                if (((m + n) & 1) == 0) {
                    return (double)(max(left1, left2) + min(right1, right2)) / 2;
                } else {
                    return (double)max(left1, left2);
                }
            } else if (left1 > right2) {
                right = cut1 - 1;
            } else {
                left = cut1 + 1;
            }
        }
        return -1;
    }
};
//Time : O(log(min(m, n)))
//Space : O(1)