class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> myMap;
        stack<int> myStack;
        myStack.push(-1);
        for (int i=0; i<nums1.size(); ++i) {
            myMap[nums1[i]] = i;
        }
        
        for (int i=0; i<nums2.size(); ++i) {
            while (myStack.top() != -1 && nums2[i] > nums2[myStack.top()]) {
                if (myMap.find(nums2[myStack.top()]) != myMap.end()) {
                    ans[myMap[nums2[myStack.top()]]] = nums2[i];
                }
                myStack.pop();
            }
            myStack.push(i);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)