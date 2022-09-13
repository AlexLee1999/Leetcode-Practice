class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr(n);
        int mod = 1e9 + 7;
        for (int i=0; i<n; ++i) {
            arr[i] = {efficiency[i], speed[i]};
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> myHeap;
        long long total_speed = 0;
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            int min_efficiency = arr[i].first;
            total_speed += arr[i].second;
            ans = max(ans, (long long)total_speed * min_efficiency);
            myHeap.push(arr[i].second);
            while (myHeap.size() > k - 1) {
                total_speed -= myHeap.top();
                myHeap.pop();
            }
        }
        return ans % mod;
    }
};
// Time : O(nlogn + (n - k)logk)
// Space : O(n + k)