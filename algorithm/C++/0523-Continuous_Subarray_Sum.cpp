class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int sum = 0;
        myMap[0] = -1;// prefix sum before index 0 is 0
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            sum %= k;
            if (myMap.find(sum) != myMap.end()) {
                if (i - myMap[sum] >= 2) {
                    return true;
                }
            } else {
                myMap[sum] = i;
            }
            
        }
        return false;
    }
};
// Time : O(n)
// Space : O(n)