class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *min_element(nums.begin(), nums.end());
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        int right = sum;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& nums, int m, int val) {
        int count = 0;
        int cur = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > val) {
                return false;
            }
            if (cur + nums[i] > val) {
                count ++;
                cur = 0;
            }
            cur += nums[i];
            if (count >= m) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nlogn)
// Space : O(1)