class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        myMap[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (myMap.find(sum - k) != myMap.end()) {
                count += myMap[sum - k];
            }
            myMap[sum]++;
        }
        return count;
    }
};