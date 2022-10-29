class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        for (int i=0; i<nums2.size(); ++i) {
            myMap[nums2[i]] = i;
        }
        vector<int> ans(nums1.size(), 0);
        for (int i=0; i<nums1.size(); ++i) {
            ans[i] = myMap[nums1[i]];
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)