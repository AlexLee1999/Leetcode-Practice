class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0;
        double right = stations.back() - stations[0];
        
        while (right - left > 0.000001) {
            double mid = left + (double)(right - left) / 2.0;
            if (isPossible(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
    bool isPossible(vector<int>& stations, int k, double dist) {
        int count = 0;
        for (int i=1; i<stations.size(); ++i) {
            count += ((int)ceil((stations[i] - stations[i - 1]) / dist) - 1);
            if (count > k) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nlogW) W is the range/precision
// Space : O(1)