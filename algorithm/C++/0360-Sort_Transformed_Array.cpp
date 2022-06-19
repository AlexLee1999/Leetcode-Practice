class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans(nums.size(), 0);
        
        if (a > 0) {
            int left = 0;
            int right = nums.size() - 1;
            int pos = nums.size() - 1;
            while (left <= right) {
                if (func(a, b, c, nums[left]) < func(a, b, c, nums[right])) {
                    ans[pos] = func(a, b, c, nums[right]);
                    pos --;
                    right --;
                } else {
                    ans[pos] = func(a, b, c, nums[left]);
                    pos --;
                    left ++;
                }
            }
        } else {
            int left = 0;
            int right = nums.size() - 1;
            int pos = 0;
            while (left <= right) {
                if (func(a, b, c, nums[left]) > func(a, b, c, nums[right])) {
                    ans[pos] = func(a, b, c, nums[right]);
                    pos ++;
                    right --;
                } else {
                    ans[pos] = func(a, b, c, nums[left]);
                    pos ++;
                    left ++;
                }
            }
        }
        return ans;
    }
    int func(int a, int b, int c, int x) {
        return a * pow(x, 2) + b * x + c;
    }
};
// Time : O(n)
// Space : O(n)