class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        for (int i=0; i<nums1.size(); ++i) {
            myHeap.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> ans;
        while (!myHeap.empty()) {
            pair<int, pair<int, int>> front = myHeap.top();
            myHeap.pop();
            int idx1 = front.second.first;
            int idx2 = front.second.second;
            ans.push_back({nums1[idx1], nums2[idx2]});
            if (ans.size() == k) {
                return ans;
            }
            if (idx2 + 1 < nums2.size()) {
                myHeap.push({nums1[idx1] + nums2[idx2 + 1], {idx1, idx2 + 1}});
            }
        } 
        return ans;
    }
};
// Time : O(min(k, m + n)logm)
// Space : O(m)