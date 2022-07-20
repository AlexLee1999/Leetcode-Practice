class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left = 0;
        int right = *max_element(arr.begin(), arr.end());
        int cur_diff = INT_MAX;
        int optimal = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = calculateSum(arr, mid);
            if (sum > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (cur_diff > abs(sum - target)) {
                optimal = mid;
                cur_diff = abs(sum - target);
            } else if (cur_diff == abs(sum - target)) {
                optimal = min(optimal, mid);
            }
        }
        return optimal;
    }
    int calculateSum(vector<int>& arr, int val) {
        int count = 0;
        for (int i=0; i<arr.size(); ++i) {
            count += min(arr[i], val);
        }
        return count;
    }
};
// Time : O(nlogk)
// Space : O(1)