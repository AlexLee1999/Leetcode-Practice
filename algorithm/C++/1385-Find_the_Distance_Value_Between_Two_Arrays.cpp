class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = arr1.size();
        for (int i=0; i<arr1.size(); ++i) {
            int target = arr1[i];
            int left = 0;
            int right = arr2.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr2[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            // Three outcomes of right : -1, size()-1, [0~size-2]
            if (right == arr2.size() - 1 && abs(arr2[right] - target) <= d) {
                ans --;
            }
            if (right == -1 && abs(arr2[right + 1] - target) <= d) {
                ans --;
            }
            if (right < arr2.size() - 1 && (abs(arr2[right] - target) <= d || abs(arr2[right + 1] - target) <= d)) {
                ans --;
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(1)