class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = neededTime.size();
        int i = 0;
        while(i < n) {
            char color = colors[i];
            int sum = 0;
            int max_time = 0;
            while (i < n && colors[i] == color) {
                sum += neededTime[i];
                max_time = max(max_time, neededTime[i]);
                i ++;
            }
            ans += sum - max_time;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)