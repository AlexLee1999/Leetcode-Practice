class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> myStack;
        vector<int> ans (nums.size(), -1);
        for (int i=0; i < 2* nums.size(); ++i) {
            int j = i % nums.size();
            while (!myStack.empty() && myStack.top().first < nums[j]) {
                pair<int, int> top = myStack.top();
                myStack.pop();
                if (ans[top.second] == -1) {
                    ans[top.second] = nums[j];
                }
            }
            myStack.push({nums[j], j});
        }
        return ans;
    }
};