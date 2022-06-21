class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> table(n, 0);
        deque<int> myDeque;
        table[0] = nums[0];
        myDeque.push_back(0);
        for (int i=1; i<n; ++i) {
            while (!myDeque.empty() && myDeque.front() < i-k) {
                myDeque.pop_front();
            }
            table[i] = nums[i] + table[myDeque.front()];
            while (!myDeque.empty() && table[myDeque.back()] < table[i]) {
                myDeque.pop_back();
            }
            myDeque.push_back(i);
        }
        return table[n - 1];
    }
};
// Time : O(n)
// Space : O(n + k)