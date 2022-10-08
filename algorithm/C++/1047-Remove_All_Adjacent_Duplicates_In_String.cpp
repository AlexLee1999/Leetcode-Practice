class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> myStack;
        for (int i=0; i<s.size(); ++i) {
            if (i<s.size() && !myStack.empty() && s[i] == myStack.top()) {
                myStack.pop();
            } else {
                myStack.push(s[i]);
            }
        }
        string ans = "";
        while (!myStack.empty()) {
            ans += myStack.top();
            myStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(n)
// Space : O(n)