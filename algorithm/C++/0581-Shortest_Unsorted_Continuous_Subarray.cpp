class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> myStack;
        int left = nums.size();
        for (int i=0; i<nums.size(); ++i) {
            while (!myStack.empty() && nums[myStack.top()] > nums[i]) {
                left = min(left, myStack.top());
                myStack.pop();
            }
            myStack.push(i);
        }
        stack<int> myStack1;
        int right = 0;
        for (int i=nums.size() - 1; i >= 0; --i) {
            while(!myStack1.empty() && nums[myStack1.top()] < nums[i]) {
                right = max(right, myStack1.top());
                myStack1.pop();
            }
            myStack1.push(i);
        }
        if (right < left) {
            return 0;
        }
        return right - left + 1;
    }
};
// Time : O(n)
// Space : O(n)