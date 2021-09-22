class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int left = 0;
        int right = 0;
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                ans.push_back(nums1[left]);
                left ++;
            }
            else {
                ans.push_back(nums2[right]);
                right ++;
            }
        }
        while (left < m) {
            ans.push_back(nums1[left]);
            left ++;
        }
        while (right < n) {
            ans.push_back(nums2[right]);
            right ++;
        }
        for (int i=0; i<m+n; ++i) {
            nums1[i] = ans[i];
        }
    }
};