class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i=2; i<n; ++i) {
            int left = 0;
            int right = i-1;
            while (left < right) {
                if (nums[i] >= nums[left] + nums[right]) {
                    left ++;
                } else {
                    sum += (right - left);
                    right --;
                }
            }
        }
        return sum;
    }
};