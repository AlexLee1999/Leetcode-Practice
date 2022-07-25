class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> myMap;
        
        int len = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (myMap.count(nums[i])) {
                continue;
            }
            auto left_ptr = myMap.find(nums[i] - 1); 
            auto right_ptr = myMap.find(nums[i] + 1);
            // We use find to prevent adding key-value in hashmap
            int left = left_ptr != myMap.end() ? left_ptr->second : 0;
            int right = right_ptr != myMap.end() ? right_ptr->second : 0;
            int total = left + right + 1;
            myMap[nums[i]] = total;
            myMap[nums[i] - left] = total;
            myMap[nums[i] + right] = total;
            len = max(len, total);
        }
        return len;
    }
};
// Time : O(n)
// Space : O(n)