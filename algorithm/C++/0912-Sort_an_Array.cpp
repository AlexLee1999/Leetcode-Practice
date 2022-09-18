class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> myHeap(nums.begin(), nums.end());
        vector<int> ans(nums.size(), 0);
        int ptr = 0;
        while (!myHeap.empty()) {
            ans[ptr] = myHeap.top();
            myHeap.pop();
            ptr ++;
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)