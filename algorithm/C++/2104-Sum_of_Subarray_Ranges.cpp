class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> myStack_max;
        myStack_max.push(-1);
        long long max_sum = 0;
        for (int i=0; i<=nums.size(); ++i) {
            while (myStack_max.top() != -1 && (i == nums.size() || nums[myStack_max.top()] <= nums[i])) {
                int idx = myStack_max.top();
                myStack_max.pop();
                int height = nums[idx];
                int left = idx - myStack_max.top();
                int right = i - idx;
                max_sum += ((long long)height * (long long)left * (long long)right);
            }
            myStack_max.push(i);
        }
        long long min_sum = 0;
        stack<int> myStack_min;
        myStack_min.push(-1);
        for (int i=0; i<=nums.size(); ++i) {
            while (myStack_min.top() != -1 && (i == nums.size() || nums[myStack_min.top()] >= nums[i])) {
                int idx = myStack_min.top();
                myStack_min.pop();
                int height = nums[idx];
                int left = idx - myStack_min.top();
                int right = i - idx;
                min_sum += ((long long)height * (long long)left * (long long)right);
            }
            myStack_min.push(i);
        }
        return max_sum - min_sum;
    }
};
// Time : O(n)
// Space : O(n)
// idea : from 907, we can find the min sum of every subarray, here, we calculate the max sum of every subarray
// Ans = max_sum - min_sum