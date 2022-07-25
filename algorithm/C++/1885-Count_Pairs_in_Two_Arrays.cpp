class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n, 0);
        long long count = 0;
        for (int i=0; i<n; ++i) {
            diff[i] = (nums1[i] - nums2[i]);
        }
        
        sort(diff.begin(), diff.end());
        for (int i=0; i<n; ++i) {
            auto it = upper_bound(diff.begin() + i + 1, diff.end(), -diff[i]);
            count += (diff.end() - it);
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(n)
/* Idea : nums1[i] + nums1[j] > nums2[i] + nums2[j] => nums1[i] - nums2[i] > nums1[j] - nums2[j] */