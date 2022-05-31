class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> myStack;
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> myMap;
        for (int i=0; i<nums1.size(); ++i) {
            myMap[nums1[i]] = i;
        }
        for (int i=0; i<nums2.size(); ++i) {
            while (!myStack.empty() && nums2[i] > myStack.top()) {
                int top = myStack.top();
                myStack.pop();
                if (myMap.count(top) != 0) {
                    ans[myMap[top]] = nums2[i];
                }
            }
            myStack.push(nums2[i]);
        }
        return ans;
    }
};