class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> myHeap;
        for (int i=0; i<sticks.size(); ++i) {
            myHeap.push(sticks[i]);
        }
        int cost = 0;
        while (myHeap.size() > 1) {
            int first = myHeap.top();
            myHeap.pop();
            int second = myHeap.top();
            myHeap.pop();
            cost += first;
            cost += second;
            myHeap.push(first + second);
        }
        return cost;
    }
};
// Time : O(nlogn)
// Space : O(n)