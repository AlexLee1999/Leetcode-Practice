class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> myStack;
        vector<int> ans(s.size() + 1);
        int ptr = 0;
        for (int i=1; i<=s.size() + 1; ++i) {
            myStack.push(i);
            if (i - 1 < s.size() && s[i - 1] == 'I') {
                while (!myStack.empty()) {
                    ans[ptr] = myStack.top();
                    myStack.pop();
                    ptr ++;
                }
            }
        }
        while (!myStack.empty()) {
            ans[ptr] = myStack.top();
            myStack.pop();
            ptr ++;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)