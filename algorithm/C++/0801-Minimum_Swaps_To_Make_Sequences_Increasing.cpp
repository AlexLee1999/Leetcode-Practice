class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> swap(n, INT_MAX);
        vector<int> no_swap(n, INT_MAX);
        swap[0] = 1;
        no_swap[0] = 0;
        for (int i=1; i<n; ++i) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) { // is increasing
                swap[i] = min(swap[i], swap[i - 1] + 1); // swap both i and i-1
                no_swap[i] = min(no_swap[i], no_swap[i - 1]); 
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) { // can swap
                swap[i] = min(swap[i], no_swap[i - 1] + 1);
                no_swap[i] = min(no_swap[i], swap[i - 1]); 
            }
        }
        return min(swap[n - 1], no_swap[n - 1]);
    }
};
// Time : O(n)
// Space : O(n)