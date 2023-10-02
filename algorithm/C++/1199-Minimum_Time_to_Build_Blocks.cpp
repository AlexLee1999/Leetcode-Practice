class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> myHeap;
        for (int i=0; i<blocks.size(); ++i) {
            myHeap.push(blocks[i]);
        }
        while (myHeap.size() > 1) {
            int first = myHeap.top();
            myHeap.pop();
            int second = myHeap.top();
            myHeap.pop();
            myHeap.push(second + split);
        }
        return myHeap.top();
    }
};