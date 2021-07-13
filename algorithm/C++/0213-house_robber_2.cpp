class Solution {
public:
    int rob_sub(vector<int>& nums){
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
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> tmp1(nums.begin(), nums.end()-1);
        vector<int> tmp2(nums.begin()+1, nums.end());
        int res1 = rob_sub(tmp1);
        int res2 = rob_sub(tmp2);
        return max(res1, res2);
    }

};
