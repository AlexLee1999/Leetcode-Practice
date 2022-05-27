class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i=0; i<n-2; ++i) {
            for (int j=i+1; j<n-1; j++) {
                sum += count(nums, i, j);
            }
        }
        return sum;
    }
    int count(vector<int>& nums, int i, int j) {
        int left = j + 1;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[i] + nums[j] <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left - j - 1;
    }
};