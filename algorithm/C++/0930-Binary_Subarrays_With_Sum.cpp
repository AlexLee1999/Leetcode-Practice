class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> myMap;
        myMap[0] ++;
        int sum = 0;
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            
            count += myMap[sum - goal];
            myMap[sum] ++;
        }
        return count;
    }
};
// Time : O(n)
// Space : O(n)