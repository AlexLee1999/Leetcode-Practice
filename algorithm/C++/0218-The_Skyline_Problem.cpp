class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> height;
        multiset<int> mySet;
        int prev_height = 0;
        int cur_height = 0;
        for (int i=0; i<buildings.size(); ++i) {
            height.push_back({buildings[i][0], buildings[i][2]});
            height.push_back({buildings[i][1], -buildings[i][2]}); // set end with negitive height
        }
        sort(height.begin(), height.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // start is before end if same place
            }
            return a[0] < b[0];
        });
        mySet.insert(0);
        for (int i=0; i<height.size(); ++i) {
            if (height[i][1] > 0) {
                mySet.insert(height[i][1]);
            } else {
                mySet.erase(mySet.find(-height[i][1]));
            }
            cur_height = *mySet.rbegin();
            if (cur_height != prev_height) {
                ans.push_back({height[i][0], cur_height});
                prev_height = cur_height;
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)