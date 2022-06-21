class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> myDeque;
        vector<int> ans;
        int max_num = INT_MIN;
        for (int i=0; i<k; ++i) {
            while (!myDeque.empty() && nums[myDeque.back()] < nums[i]) {
                myDeque.pop_back();
            }
            max_num = max(max_num, nums[i]);
            myDeque.push_back(i);
        }
        ans.push_back(max_num);
        for (int i=k; i<n; ++i) {
            while (!myDeque.empty() && myDeque.front() <= i - k) {
                myDeque.pop_front();
            }
            while (!myDeque.empty() && nums[myDeque.back()] < nums[i]) {
                myDeque.pop_back();
            }
            
            myDeque.push_back(i);
            ans.push_back(nums[myDeque.front()]); 
            
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)