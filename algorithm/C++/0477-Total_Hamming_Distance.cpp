class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        vector<int> table(32, 0);
        int n = nums.size();
        for (int i=0; i<nums.size(); ++i) {
            int z = nums[i];
            int j = 0;
            while (z > 0) {
                table[j] += z & 1;
                z  >>= 1;
                j ++;
            }
        }
        for (int i=0; i<32; ++i) {
            count += table[i] * (n - table[i]); // table[i] = number of element with the ith bit == 1
        }
        return count;
    }
};