class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myDeque;
        vector<int> ans;
        for (int i=0; i<k; ++i) {
            while (!myDeque.empty() && nums[myDeque.back()] <= nums[i]) {
                myDeque.pop_back();
            }
            myDeque.push_back(i);
        }
        ans.push_back(nums[myDeque.front()]);
        for (int i=k; i< nums.size(); ++i) {
            while (!myDeque.empty() && myDeque.front() <= i - k) {
                myDeque.pop_front();
            }
            while (!myDeque.empty() && nums[myDeque.back()] <= nums[i]) {
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