class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num1_left = m - 1;
        int num2_left = n - 1;
        int space_ptr = nums1.size() - 1;
        while (num1_left >= 0 && num2_left >= 0) {
            if (nums1[num1_left] >= nums2[num2_left]) {
                nums1[space_ptr] = nums1[num1_left];
                num1_left --;
            } else {
                nums1[space_ptr] = nums2[num2_left];
                num2_left --;
            }
            space_ptr --;
        }
        while (num1_left >= 0) {
            nums1[space_ptr] = nums1[num1_left];
            num1_left --;
            space_ptr --;
        }
        while (num2_left >= 0) {
            nums1[space_ptr] = nums2[num2_left];
            num2_left --;
            space_ptr --;
        }
    }
};
// Time : O(m + n)
// Space : O(1)