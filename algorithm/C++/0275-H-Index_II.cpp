class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (n - 1 - mid >= citations[mid]) {  // n - 1 - mid is the number of papers with citations >= citations[mid]
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return n - 1 - right;
    }
};
// Time : O(logn)
// Space : O(1)