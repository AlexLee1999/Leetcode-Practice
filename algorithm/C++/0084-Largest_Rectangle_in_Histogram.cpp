class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> myStack;
        myStack.push(-1);
        int max_area = 0;
        for (int i=0; i<heights.size(); ++i) {
            while (myStack.top() != -1 && heights[i] <= heights[myStack.top()]) {
                int height = heights[myStack.top()];
                myStack.pop();
                
                int width = i - 1 - myStack.top();
                max_area = max(max_area, width * height);
            }
            myStack.push(i);
        }
        while (myStack.top() != -1) {
            int height = heights[myStack.top()];
            myStack.pop();
            int width = heights.size() - 1 - myStack.top();
            max_area = max(max_area, width * height);
        }
        return max_area;
    }
};
// Time : O(n)
// Space : O(n)