class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = 10000000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(candies, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right; //If cannot allocate, mid = 1 and right = 0
    }
    bool isPossible(vector<int>& candies, long long k, int candynum) {
        long long pilenum = 0;
        for (int i=0; i<candies.size(); ++i) {
            pilenum += (candies[i] / candynum);
        }
        return pilenum >= k;
    }
};
// Time : O(log(n))
// Space : O(1)