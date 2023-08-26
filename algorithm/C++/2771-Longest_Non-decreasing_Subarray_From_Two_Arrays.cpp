class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> table(n + 1, vector<int>(2, 0));
        table[1][0] = 1;
        table[1][1] = 1;
        int current_max = 1;
        int a1 = 1;
        int a2 = 1;
        for (int i=1; i<n; ++i) {
            int a11 = 0;
            int a12 = 0;
            int a21 = 0;
            int a22 = 0;
            if (nums1[i] >= nums2[i - 1]) {
                a21 = a2 + 1;
            } else {
                a21 = 1;
            }
            if (nums2[i] >= nums1[i - 1]) {
               a12 = a1 + 1;
            } else {
                a12 = 1;
            }
            if (nums1[i] >= nums1[i - 1]) {
                a11 = a1 + 1;
            } else {
                a11 = 1;
            }
            if (nums2[i] >= nums2[i - 1]) {
                a22 = a2 + 1;
            } else {
                a22 = 1;
            }
            a1 = max(a21, a11);
            a2 = max(a22, a12);
            current_max = max(current_max, max(a1, a2));
        }
        return current_max;
    }
};