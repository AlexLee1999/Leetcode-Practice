class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 10000000;
        if (hour <= (double)(dist.size() - 1)) {
            return -1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(dist, hour, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& dist, double hour, int speed) {
        double time = 0;
        for (int i=0; i<dist.size() - 1; ++i) {
            time += ceil((double)dist[i] / (double)speed);
            if (time > hour) {
                return false;
            }
        }
        time += (double)dist[dist.size() - 1] / (double)speed;
        return time <= hour;
    }
};