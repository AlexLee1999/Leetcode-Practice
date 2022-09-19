class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int min_num = *min_element(nums.begin(), nums.end());
        long long sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        return sum - min_num * nums.size();
    }
};
// Time : O(n)
// Space : O(n)