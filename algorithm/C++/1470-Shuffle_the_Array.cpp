class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n, 0);
        int ptr = 0;
        for (int i=0; i<n; ++i) {
            ans[ptr] = nums[i];
            ptr ++;
            ans[ptr] = nums[i + n];
            ptr ++;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)