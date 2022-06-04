class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) {
            return -1;
        }
        int left = 0;
        int right = 1000000000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int bouquet_num = 0;
        int length = 0;
        for (int i=0; i<bloomDay.size(); ++i) {
            if (bloomDay[i] <= day) {
                length ++;
                if (length >= k) {
                    bouquet_num ++;
                    length = 0;
                }
            } else {
                length = 0;
            }
        }
        return bouquet_num >= m;
    }
};