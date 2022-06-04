class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        if (nums1.size() < nums2.size()) {
            return intersect(nums2, nums1);
        }
        for(int i = 0; i < nums1.size(); ++i) {
            myMap[nums1[i]] ++;
        }
        vector<int> ans;
        for (int j = 0; j < nums2.size(); ++j) {
            if (myMap[nums2[j]] > 0) {
                ans.push_back(nums2[j]);
                myMap[nums2[j]] --;
            }
        }
        return ans;
    }
};