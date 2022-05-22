class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (int i=0; i<timePoints.size(); ++i) {
            string hour = timePoints[i].substr(0, 2);         
            string minute = timePoints[i].substr(3, 2);
            int time = stoi(hour) * 60 + stoi(minute);
            times.push_back(time);
        }
        sort(times.begin(), times.end());
        int gap = INT_MAX;
        int n = times.size();
        for (int i=0; i<times.size()-1; ++i) {
            gap = min(gap, min(abs(times[i] - times[i + 1]), 1440 - abs(times[i] - times[i + 1])));
        }
        gap = min(gap, min(abs(times[0] - times[n-1]), 1440 - abs(times[0] - times[n-1])));
        return gap;
    }
};