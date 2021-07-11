class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> table (n, 0);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        table[0] = nums[0];
        table[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; ++i){
            table[i] = max(nums[i]+table[i-2], table[i-1]);
        }
        return table[n-1];
    }
};
