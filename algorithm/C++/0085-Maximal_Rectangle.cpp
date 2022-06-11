class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> nums(matrix[0].size(), 0);
        int max_area = 0;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    nums[j] = nums[j] + 1;
                } else {
                    nums[j] = 0;
                }
            }
            max_area = max(max_area, maxArea(nums));
        }
        return max_area;
    }
    int maxArea(vector<int>& nums) {
        stack<int> myStack;
        myStack.push(-1);
        int max_area = 0;
        for (int i=0; i<nums.size(); ++i) {
            while (myStack.top() != -1 && nums[myStack.top()] >= nums[i]) {
                int height = nums[myStack.top()];
                myStack.pop();
                int width = i - 1 - myStack.top();
                max_area = max(max_area, height * width);
            }
            myStack.push(i);
        }
        while (myStack.top() != -1) {
            int height = nums[myStack.top()];
            myStack.pop();
            int width = nums.size() - 1 - myStack.top();
            max_area = max(max_area, height * width);
        }
        return max_area;
    }
};
// Time : O(kn)
// Space : O(n + k)