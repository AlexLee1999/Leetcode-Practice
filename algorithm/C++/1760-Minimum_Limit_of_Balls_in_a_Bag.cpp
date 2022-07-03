class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& nums, int maxOperations, int limit) {
        int oper = 0;
        for (int i=0; i<nums.size(); ++i) {
            double part = (double)nums[i] / (double)limit;
            oper += ceil(part) - 1;
            if (oper > maxOperations) {
                return false;
            }
        }
        
        return true;
    }
};
// Time : O(nlogk) k is the max element
// Space : O(1)