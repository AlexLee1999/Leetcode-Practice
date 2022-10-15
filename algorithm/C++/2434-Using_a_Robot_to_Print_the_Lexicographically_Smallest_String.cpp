class Solution {
public:
    string robotWithString(string s) {
        stack<char> myStack;
        string ans = "";
        
        vector<char> minElement(s.size());
        char min_ele = s.back();
        for (int i=s.size() - 1; i >= 0; --i) {
            min_ele = min(min_ele, s[i]);
            minElement[i] = min_ele;
        }
        reverseStr(s, 0, myStack, ans, minElement);
        while (!myStack.empty()) {
            ans += myStack.top();
            myStack.pop();
        }
        return ans;
    }
    void reverseStr(string& s, int left, stack<char>& myStack, string& ans, vector<char>& minElement) {
        if (left >= s.size()) {
            return;
        }
        char min_char = minElement[left];
        
        for (int i=left; i<s.size(); ++i) {
             if (!myStack.empty() && myStack.top() <= min_char) {
                while (!myStack.empty() && myStack.top() <= min_char) {
                    ans += myStack.top();
                    myStack.pop();
                }
            } 
            if (s[i] == min_char) {
                ans += min_char;
                reverseStr(s, i + 1, myStack, ans, minElement);
                return;
            } else {
                myStack.push(s[i]);
            }
        }
        
    }
};
// Time : O(n)
// Space : O(n)