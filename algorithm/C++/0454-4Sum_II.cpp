class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> myMap;
        int count = 0;
        for (int i=0; i<nums1.size(); ++i) {
            for (int j=0; j<nums2.size(); ++j) {
                myMap[nums1[i] + nums2[j]] ++;
            }
        }
        for (int i=0; i<nums3.size(); ++i) {
            for (int j=0; j<nums4.size(); ++j) {
                if (myMap.find(-(nums3[i] + nums4[j])) != myMap.end()) {
                    count += myMap.find(-(nums3[i] + nums4[j]))->second;
                }
            }
        }
        return count;
    }
};