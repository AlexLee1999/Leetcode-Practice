class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> myStack;
        vector<int> ans(temperatures.size(), 0);
        for (int i=0; i<temperatures.size(); ++i) {
            while (!myStack.empty() && temperatures[i] > myStack.top().first) {
                pair<int, int> top = myStack.top();
                myStack.pop();
                if (ans[top.second] == 0) {
                    ans[top.second] = i - top.second;
                }
            }
            myStack.push({temperatures[i], i});
        }
        return ans;
    }
};