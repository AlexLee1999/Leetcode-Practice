class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long diff = 0;
        for (int i=0; i<nums.size(); ++i) {
            diff ^= nums[i];
        }
        diff &= -diff; //find the lowest 1 bit
        int res1 = 0;
        int res2 = 0;
        for (int i=0; i<nums.size(); ++i) {
            if ((nums[i] & diff) == 0) { //one number will go here
                res1 ^= nums[i];
            } else if ((nums[i] & diff) != 0) { //another number will go here
                res2 ^= nums[i];
            }
        }
        return vector<int> {res1, res2};
    }
};