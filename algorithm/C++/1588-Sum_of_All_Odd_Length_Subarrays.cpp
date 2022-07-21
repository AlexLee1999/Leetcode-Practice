class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        vector<int> prefix(n + 1, 0);
        for (int i=0; i<n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        for (int len = 1; len <= n; len += 2) {
            for (int start = 0; start + len <= n; ++start) {
                int end = start + len;
                count += (prefix[end] - prefix[start]);
            }
        }
        return count;
    }
};
// Time : O(n^2)
// Space : O(n)
