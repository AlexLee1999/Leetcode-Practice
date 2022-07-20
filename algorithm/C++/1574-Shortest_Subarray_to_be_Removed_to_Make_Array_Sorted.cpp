class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int end = n - 1;
        while (end > 0 && arr[end - 1] <= arr[end]) {
            end --;
        }
        if (end == 0) {
            return 0;
        }
        int ans = end;
        for (int start=0; start<n; ++start) {
            if (start > 0 && arr[start] < arr[start - 1]) {
                break;
            }
            while (end < n && arr[start] > arr[end]) {
                end ++;
            }
            ans = min(ans, end - start - 1);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)