class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n == 1) {
            return 0;
        }
        if (n == k) {
            return 0;
        }

        vector<int> arr;
        for (int i=0; i<n - 1; ++i) {
            arr.push_back(weights[i] + weights[i + 1]);
        }
        sort(arr.begin(), arr.end());
        long long smallest = 0;
        long long  largest = 0;
        for (int i=0; i<k - 1; ++i) {
            smallest += arr[i];
            largest += arr[n - 2 - i];
        }
        return largest - smallest;
    }
};
// Time : O(nlogn)
// Space : O(n)