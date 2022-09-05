class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        int tmp = num;
        while (tmp > 0) {
            arr.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(arr.begin(), arr.end());
        int max_right = arr.size() - 1;
        int max_digit = arr.back();
        vector<int> swap_pairs;
        int i = arr.size() - 1;
        while (i >= 0) {
            if (arr[i] > max_digit) {
                max_digit = arr[i];
                max_right = i;
            } else if (arr[i] < max_digit) {
                swap_pairs = {i, max_right};
            }
            i --;
        }
        if (swap_pairs.empty()) {
            return num;
        }
        swap(arr[swap_pairs[0]], arr[swap_pairs[1]]);
        int ans = arr[0];
        for (int i=1; i<arr.size(); ++i) {
            ans *= 10;
            ans += arr[i];
        }
        return ans;
    }
};
// Time : O(logn)
// Space : O(logn)