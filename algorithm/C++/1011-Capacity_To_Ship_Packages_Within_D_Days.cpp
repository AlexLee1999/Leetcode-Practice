class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int i=0; i<weights.size(); ++i) {
            sum += weights[i];
        }
        
        int left = *max_element(weights.begin(),  weights.end());
        int right = sum;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(weights, days, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool isPossible(vector<int>& weights, int days, int capacity) {
        int i = 0;
        int cur = 0;
        int num_days = 1;
        while (i < weights.size()) {
            if (weights[i] > capacity) {
                return false;
            }
            if (cur + weights[i] <= capacity) {
                cur += weights[i];
                i++;
            } else{
                cur = 0;
                num_days ++;
                if (num_days > days) {
                    return false;
                }
            }
        }
        return num_days <= days;
    }
};
// Time : O(logn)
// Space : O(logn)