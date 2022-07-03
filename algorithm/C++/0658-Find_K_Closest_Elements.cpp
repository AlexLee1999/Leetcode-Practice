class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1 - k;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) { // Find the left bound of the array
                left = mid + 1;
            } else if (x - arr[mid] <= arr[mid + k] - x) { //prefer smaller if distance is same
                right = mid - 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
// Time : O(log n)
// Space : O(k)