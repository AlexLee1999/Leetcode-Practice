class Solution {
public:
    string decodeString(string s) {
        stack<char> myStack;
        string ans = "";
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ']') {
                string cur = "";
                while (myStack.top() != '[') {
                    if (myStack.top() >= 'a' && myStack.top() <= 'z') {
                        cur = myStack.top() + cur;
                        myStack.pop();
                    }
                }
                myStack.pop();
                int times = 0;
                int base = 1;
                while (!myStack.empty() && myStack.top() >= '0' && myStack.top() <= '9') {
                    times += (myStack.top() - '0') * base;
                    base *= 10;
                    myStack.pop();
                }

                for (int i=0; i<times; ++i) {
                    for (int j=0; j < cur.size(); ++j) {
                        myStack.push(cur[j]);
                    }
                }
            } else {
                myStack.push(s[i]);
            }
        }
        while (!myStack.empty()) {
            ans = myStack.top() + ans;
            myStack.pop();
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)