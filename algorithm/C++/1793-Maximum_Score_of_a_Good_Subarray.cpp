class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> myStack;
        myStack.push(-1);
        int max_area = 0;
        for (int i=0; i<nums.size(); ++i) {
            while (myStack.top() != -1 && nums[myStack.top()] >= nums[i]) {
                int height = nums[myStack.top()];
                myStack.pop();
                int width = i - 1 - myStack.top();
                if (i > k && myStack.top() < k) { // Subarr [myStack.top()+1~i-1]
                    max_area = max(max_area, height * width);
                }
            }
            myStack.push(i);
        }
        while (myStack.top() != -1) {
            int height = nums[myStack.top()];
            myStack.pop();
            int width = nums.size() - 1 - myStack.top();
            if (nums.size() > k && myStack.top() < k) { // Subarr [myStack.top()+1~nums.size()-1]
                max_area = max(max_area, height * width);
            }
        }
        return max_area;
    }
};
// Time : O(n)
// Space : O(n)