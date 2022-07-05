class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0) {
            return {};
        }
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i < firstList.size() && j < secondList.size()) {
            if (firstList[i][0] <= secondList[j][1] && secondList[j][0] <= firstList[i][1]) {
                ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }
            if (secondList[j][1] > firstList[i][1]) {
                i ++;
            } else {
                j ++;
            }
        }
        return ans;
    }
};
// Time : O(m + n)
// Space : O(m + n)