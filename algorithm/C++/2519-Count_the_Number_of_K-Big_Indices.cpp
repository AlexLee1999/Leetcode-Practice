class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        priority_queue<int> left;
        priority_queue<int> right;
        int n = nums.size();
        int count = 0;
        vector<bool> valid(n, false);
        for (int i=0; i<k; ++i) {
            left.push(nums[i]);
            right.push(nums[n - 1 - i]);
        }
        for (int i=k; i<n; ++i) {
            if (left.top() < nums[i]) {
                valid[i] = true;
            }
            left.push(nums[i]);
            if (left.size() > k) {
                left.pop();
            }
        }
        for (int i=n - k - 1; i>=0; --i) {
            if (right.top() < nums[i] && valid[i]) {
                count ++;
            }
            right.push(nums[i]);
            if (right.size() > k) {
                right.pop();
            }
        }
        return count;
    }
};