class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        stack<int> myStack;
        int j = 0;
        for (int i=0; i<n; ++i) {
            myStack.push(pushed[i]);
            while (!myStack.empty() && myStack.top() == popped[j]) {
                myStack.pop();
                j ++;
            }
        }
        return myStack.empty();
    }
};