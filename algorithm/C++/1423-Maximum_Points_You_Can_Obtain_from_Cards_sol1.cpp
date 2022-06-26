class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<cardPoints.size(); ++i) {
            prefix[i+1] = cardPoints[i] + prefix[i];
        }
        
        int min_sum = INT_MAX;
        for(int i=0; i<=k; ++i) {
            min_sum = min(min_sum, prefix[i+n-k] - prefix[i]);
        }
        return prefix[n] - min_sum;
    }
};
// Time : O(n)
// Space : O(n)