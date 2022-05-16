class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> myStack;
        vector<int> ans(s.size() + 1, 0);
        int ans_ptr = 0;
        for (int i=0; i<s.size() + 1; ++i) {
            myStack.push(i+1);
            if (s[i] == 'I') {
                while (!myStack.empty()) {
                    ans[ans_ptr] = myStack.top();
                    myStack.pop();
                    ans_ptr ++;
                }
            }
        }
        while (!myStack.empty()) {
            ans[ans_ptr] = myStack.top();
            myStack.pop();
            ans_ptr ++;
        }
        return ans;
    }
};