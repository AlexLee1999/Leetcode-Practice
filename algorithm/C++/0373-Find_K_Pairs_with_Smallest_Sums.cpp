class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        for (int i=0; i<nums1.size(); ++i) {
            myHeap.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> ans;
        for (int i=0; i<k; ++i) {
            if (myHeap.empty()) {
                return ans;
            }
            pair<int, pair<int, int>> tmp = myHeap.top();
            ans.push_back({nums1[tmp.second.first], nums2[tmp.second.second]});
            myHeap.pop();
            if (tmp.second.second < nums2.size()-1) {
                myHeap.push({nums1[tmp.second.first] + nums2[tmp.second.second + 1], {tmp.second.first, tmp.second.second + 1}});
            }
        }
        return ans;
    }
};