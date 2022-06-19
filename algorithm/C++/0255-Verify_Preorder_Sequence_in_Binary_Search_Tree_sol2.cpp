class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> myStack;
        int low = INT_MIN;
        for (int i=0; i<preorder.size(); ++i) {
            if (preorder[i] < low) {
                return false;
            }
            while (!myStack.empty() && myStack.top() < preorder[i]) {
                low = myStack.top();
                myStack.pop();
            }
            myStack.push(preorder[i]);
        }
        return true;
    }
};
// Time : O(n)
// SPace : O(n)