class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> myStack;
        myStack.push(-1);
        long long area = 0;
        int mod = 1000000000 + 7;
        for (int i=0; i<=arr.size(); ++i) {
            while (myStack.top() != -1 && (i == arr.size() || arr[i] <= arr[myStack.top()])) {
                int idx = myStack.top();
                int height = arr[idx];
                myStack.pop();
                
                int left = idx - myStack.top(); // myStack.top() is the index of previous smaller number
                int right = i - idx;
                area += (long long)((long long)height * (long long)left * (long long)right);
                area %= mod;
            }
            myStack.push(i);
        }
        return area;
    }
};