class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = maxSum;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(n, index, maxSum, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool isPossible(int n, int index, int maxSum, long long maxNum) {
        long long sum = 0;
        if (maxNum > index) {
            sum += (index) * (maxNum - index + maxNum - 1) / 2;
        } else {
            sum += (maxNum) * (maxNum - 1) / 2;
            sum += (index - maxNum + 1);
        }
        sum += maxNum;
        if (index + maxNum > n - 1) {
            sum += (maxNum - 1 + maxNum - n + 1 + index) * (n - index - 1) / 2;
        } else {
            sum += (maxNum) * (maxNum - 1) / 2;
            sum += (n - index - maxNum);
        }
        if (sum > maxSum) {
            return false;
        }
        return true;
    }
};
// Time : O(logk)
// Space : O(1)