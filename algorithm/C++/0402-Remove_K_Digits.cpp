class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> myStack;
        for (int i=0; i<num.size(); ++i) {
            while (!myStack.empty() && num[i] < myStack.top() && k > 0) {
                myStack.pop();
                k --;
            }
            myStack.push(num[i]);
        }
        for (int i=0; i<k; ++i) {
            myStack.pop();
        }
        string s = "";
        bool zero = true;
        vector<char> arr (myStack.size(), 0);
        int i = myStack.size() - 1;
        while (!myStack.empty()) {
            arr[i] = myStack.top();
            myStack.pop();
            i --;
        }
        
        for (int i = 0; i<arr.size(); ++i) {
            if (zero && arr[i] == '0') {
                continue;
            } else {
                zero = false;
                s += arr[i];
            }
        }
        return s == "" ? "0" : s;
    }
};
// Time : O(n)
// Space : O(n)