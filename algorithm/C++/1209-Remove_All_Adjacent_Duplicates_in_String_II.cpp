class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> myStack;
        for (int i=0; i<s.size(); ++i) {
            if (myStack.empty() || s[i] != myStack.top().first) {
                myStack.push({s[i], 1});
            } else if (s[i] == myStack.top().first) {
                myStack.top().second ++;
            }
            if (myStack.top().second >= k) {
                myStack.top().second -= k;
                if (myStack.top().second == 0) {
                    myStack.pop();
                }
            }
        }
        string ans = "";
        while (!myStack.empty()) {
            ans += string(myStack.top().second, myStack.top().first);
            myStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(n)
// Space : O(n)