class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> myMap;
        long prefixSum = 0;
        int longest = 0;
        for (int i=0; i<nums.size(); ++i) {
            prefixSum += nums[i];
            
            if (prefixSum == k) {
                longest = i + 1;
            }
            if (myMap.find(prefixSum - k) != myMap.end()) {
                longest = max(longest, i - myMap[prefixSum-k]);
            }
            if (myMap.find(prefixSum) == myMap.end()) {
                myMap[prefixSum] = i;
            }
        }
        return longest;
    }
};
// Time : O(n)
// Space : O(n)