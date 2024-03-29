class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            myMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = myMap[target].size();
        int ran = rand() % size;
        return myMap[target][ran];
    }
private:
    unordered_map<int, vector<int>> myMap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */