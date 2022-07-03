class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (int i=0; i<timeSeries.size() - 1; ++i) {
            total += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        total += duration;
        return total; 
    }
};
// Time : O(n)
// Space : O(1)