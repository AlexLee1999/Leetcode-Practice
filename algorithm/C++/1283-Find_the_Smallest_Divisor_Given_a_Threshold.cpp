class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, threshold, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& nums, int threshold, int div) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            float float_res = (float)nums[i] / (float)div;
            sum += ceil(float_res);
            if (sum > threshold) {
                return false;
            }
        }
        return true;
    }
};