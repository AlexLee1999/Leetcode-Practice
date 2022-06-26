class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;
        int dis = INT_MIN;
        while (left < nums1.size() && right < nums2.size()) {
            if (nums1[left] <= nums2[right]) {
                if (left <= right) {
                    dis = max(dis, right - left);
                }
                right ++;
            } else {
                left ++;
            }
        }
        return dis == INT_MIN ? 0 : dis;
    }
};
// Time : O(n)
// Space : O(1)