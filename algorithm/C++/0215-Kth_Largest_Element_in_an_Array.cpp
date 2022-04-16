class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> myPriortyQueue(less<int>(), nums);
        for (int i=0; i<k-1; ++i) {
            myPriortyQueue.pop();
        }
        return myPriortyQueue.top();
    }
};