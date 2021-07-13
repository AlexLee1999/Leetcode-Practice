class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int pre_max_pos = nums[0];
        int cur_max_pos = nums[0]; // first level search
        int step = 1; // Initial with step 1
        int pos = 0;
        if(n == 1){
            return 0;
        }
        while(cur_max_pos < n-1){
            step++;
            pre_max_pos = cur_max_pos;
            for(; pos<=pre_max_pos; ++pos){
                cur_max_pos = max(pos+nums[pos], cur_max_pos); //if cur >= n-1, break the loop
            }
        }
        return step;
    }
};