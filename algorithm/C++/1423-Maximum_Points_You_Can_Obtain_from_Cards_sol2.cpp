class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int min_sum = INT_MAX;
        int sum = 0;
        int total = 0;
        int left = 0;
        for (int right=0; right < n; ++right) {
            total += cardPoints[right];
            sum += cardPoints[right];
            if (right - left + 1 > n - k) {
                sum -= cardPoints[left];
                left ++;
            }
            if (right - left + 1 == n - k) {
                min_sum = min(min_sum, sum);
            }
        }
        return total - min_sum;
    }
};
// Time : O(n)
// Space : O(1)