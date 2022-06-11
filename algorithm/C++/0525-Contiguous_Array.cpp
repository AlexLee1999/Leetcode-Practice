class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> myMap;
        myMap[0] = -1;
        int prefix_sum = 0;
        int max_len = 0;
        for (int i=0; i<nums.size(); ++i) {
            prefix_sum += nums[i] == 1 ? 1: -1;
            if (myMap.find(prefix_sum) != myMap.end()) {
                max_len = max(max_len, i - myMap[prefix_sum]);
            } else {
                myMap[prefix_sum] = i;
            }
        }
        return max_len;
    }
};
// Time : O(n)
// Space : O(n)