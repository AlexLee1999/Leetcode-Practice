class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res (2, -1);
        if(n == 0){
            return res;
        }
        int low = 0;
        int high = n - 1;
        while(low<=high){
            int mid = (high - low) / 2 + low;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(low >= n || nums[low] != target){
            return res;
        }
        int pos = low;
        while(pos <= n-1 && nums[pos] == target){
            pos++;
        }
        res[0] = low;
        res[1] = pos-1;
        return res;


    }
};
