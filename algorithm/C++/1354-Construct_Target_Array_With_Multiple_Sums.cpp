class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }
        priority_queue<int, vector<int>, less<int>> myHeap (target.begin(), target.end());
        long sum = 0;
        for (int i=0; i<target.size(); ++i) {
            sum += target[i];
        }
        while (myHeap.top() > 1) {
            int top = myHeap.top();
            int rest = sum - top;
            myHeap.pop();
            if (rest == 1) { // special case
                return true;
            }
            int tmp = top % rest;
            if (tmp == top || tmp == 0) { // tmp == top -> rest is larger than top
                return false;
            }
            sum -= top;
            sum += tmp;
            myHeap.push(tmp);
        }
        return true;
    }
};
// Time : O(n + logklogn) // rest is always smaller than half of top
// Space : O(n)