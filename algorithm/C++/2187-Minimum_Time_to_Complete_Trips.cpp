class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = LLONG_MAX;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(time, totalTrips, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }
    bool isPossible(vector<int>& time, int totalTrips, long long days) {
        long long count = 0;
        for (int i=0; i<time.size(); ++i) {
            count += (days / time[i]);
            if (count >= totalTrips) {
                return true;
            }
        }
        return false;
    }
};
// Time : O(nlogn)
// Space : O(1)