class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> myHeap;
        int brick_sum = 0;
        for (int i=1; i<heights.size(); ++i) {
            if (heights[i] - heights[i-1] > 0) {
                myHeap.push(heights[i] - heights[i-1]);
                if (myHeap.size() > ladders) {
                    brick_sum += myHeap.top();
                    myHeap.pop();
                }
                if (brick_sum > bricks) {
                    return i - 1; // no bricks left, we can only reach to the previous spot
                }   
            }
        }
        return heights.size()-1;
    }
};
// Time : O(Nlogk)
// Space : O(k)