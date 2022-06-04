class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mySet(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int i=0; i<nums2.size(); ++i) {
            if (mySet.count(nums2[i]) != 0) {
                ans.push_back(nums2[i]);
                mySet.erase(nums2[i]);
            }
        }
        return ans;
        
    }
};