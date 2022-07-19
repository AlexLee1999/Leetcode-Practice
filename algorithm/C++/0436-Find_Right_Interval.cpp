class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> myMap;
        vector<int> ans (intervals.size(), -1);
        for (int i=0; i<intervals.size(); ++i) {
            myMap.insert({intervals[i][0], i});
        }
        for (int i=0; i<intervals.size(); ++i) {
            auto it = myMap.lower_bound(intervals[i][1]);
            if (it == myMap.end()) {
                continue;
            }
            ans[i] = it->second;
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)