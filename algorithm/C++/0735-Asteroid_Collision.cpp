class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStack;
        for (int i=0; i<asteroids.size(); ++i) {
            int push = true;
            while (!myStack.empty() && myStack.top() > 0 && asteroids[i] < 0) {
                if (abs(myStack.top()) > abs(asteroids[i])) {
                    push = false;
                    break;
                } else if (abs(myStack.top()) < abs(asteroids[i])) {
                    myStack.pop();
                } else {
                    myStack.pop();
                    push = false;
                    break;
                }
            }
            if (push) {
                myStack.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!myStack.empty()) {
            ans.push_back(myStack.top());
            myStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(n)
// Space : O(n)