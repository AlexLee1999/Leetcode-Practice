class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> arr;
        for (int i=0; i<plantTime.size(); ++i) {
            arr.push_back({plantTime[i], growTime[i]});
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        int time = 0;
        int ans = 0;
        for (int i=0; i<arr.size(); ++i) {
            time += arr[i].first;
            ans = max(ans, time + arr[i].second);
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)