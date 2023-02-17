class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet;
        for (int i=0; i<banned.size(); ++i) {
            if (banned[i] <= n) {
                bannedSet.insert(banned[i]);
            }
        }
        int left = 1;
        int right = n - bannedSet.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bannedSet, n, maxSum, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool isPossible(unordered_set<int>& bannedSet, int n, int maxSum, int current) {
        int sum = 0;
        int count = 0;
        for (int i=1; i<=n; ++i) {
            if (bannedSet.count(i)) {
                continue;
            }
            sum += i;
            count ++;
            if (sum > maxSum) {
                return false;
            }
            if (count >= current) {
                return true;
            }
        }
        return true;
    }
};
// Time : O(nlogn + B)
// Space : O(B)