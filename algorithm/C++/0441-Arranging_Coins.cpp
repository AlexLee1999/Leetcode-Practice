class Solution {
public:
    int arrangeCoins(int n) {
        long long left = (long long)0;
        long long right = (long long)n + 1;
        while (left < right) {
            long long mid = left + (right-left) /2;
            if ((mid*(mid+1))/2 > n) {
                right = mid;
            } else if ((mid*(mid+1))/2 < n) {
                left = mid + 1;
            } else if ((mid*(mid+1))/2 == n) {
                return (int)mid;
            }
        }
        return left - 1;
    }
};