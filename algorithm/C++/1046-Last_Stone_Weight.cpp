class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> myHeap;
        for (int i=0; i<stones.size(); ++i) {
            myHeap.push(stones[i]);
        }
        while (myHeap.size() >= 2) {
            int top = myHeap.top();
            myHeap.pop();
            int second = myHeap.top();
            myHeap.pop();
            if (top != second) {
                myHeap.push(abs(top - second));
            }
        }
        return myHeap.empty() ? 0 : myHeap.top();
    }
};
// Time : O(nlogn)
// Space : O(n)