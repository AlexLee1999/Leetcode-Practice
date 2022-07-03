class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int cur_max = INT_MIN;
        vector<int> ans;
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (heights[i] > cur_max) {
                ans.push_back(i);
                cur_max = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(n)
// Space : O(n)