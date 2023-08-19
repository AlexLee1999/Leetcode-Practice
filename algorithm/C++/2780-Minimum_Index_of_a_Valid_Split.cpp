class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int element = 0;
        for (int i=0; i<nums.size(); ++i) {
            myMap[nums[i]] ++;
            if (myMap[nums[i]] * 2 > nums.size()) {
                element = nums[i];
            }
        }
        unordered_map<int, int> count;
        for (int i=0; i<nums.size(); ++i) {
            count[nums[i]] ++;
            myMap[nums[i]] --;
            if (count[nums[i]] * 2 > (i + 1) && myMap[nums[i]] * 2 > (nums.size() - 1 - i)) {
                return i;
            }
        }
        return -1;
    }
};