class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        bool isStarted = false;
        int start = 0;
        vector<string> ans;
        while (i < nums.size()) {
            if (!isStarted) {
                start = i;
                isStarted = true;
                continue;
            }
            if (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
                i ++;
            } else {
                if (i - start + 1 > 1) {
                    string s = to_string(nums[start]) + "->" + to_string(nums[i]);
                    ans.push_back(s);
                    isStarted = false;
                } else {
                    string s = to_string(nums[i]);
                    ans.push_back(s);
                    isStarted = false;
                }
                i ++;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)