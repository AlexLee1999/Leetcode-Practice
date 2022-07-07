class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted(nums1);
        int optimal = INT_MIN;
        sort(sorted.begin(), sorted.end());
        long long diff = 0;
        for (int i=0; i<nums1.size(); ++i) {
            diff += abs(nums1[i] - nums2[i]);
            auto n = lower_bound(sorted.begin(), sorted.end(), nums2[i]);// find the nearest number in nums1
            if (n != sorted.begin()) {
                optimal = max(optimal, abs(nums1[i] - nums2[i]) - abs(*prev(n) - nums2[i]));
            }
            if (n != sorted.end()) {
                optimal = max(optimal, abs(nums1[i] - nums2[i]) - abs(*(n) - nums2[i]));
            }
        }
        return (diff - optimal) % (int)(1e9 + 7);
    }
};
// Time : O(nlogn)
// Space : O(n)