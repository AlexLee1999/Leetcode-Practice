class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int target = nums.size();
        vector<int> ans;
        vector<int> count(target + 1, 0);
        for (int i=0; i<nums.size(); ++i) {
             count[nums[i]] ++;
            if (count[nums[i]] == 2) {
                ans.push_back(nums[i]);
            }
        }
        for (int i=1; i<=target; ++i) {
            if (count[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)