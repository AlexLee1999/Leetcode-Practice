class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int total = 0;
        int max_total = 0;
        for (right = 0; right < fruits.size(); ++right) {
            total += fruits[right][1];
            while (left <= right && steps(startPos, fruits[right][0], fruits[left][0]) > k) {
                total -= fruits[left][1];
                left ++;
            }
            max_total = max(max_total, total);
        }
        return max_total;
    }
    int steps(int startPos, int right, int left) {
        if (left >= startPos) {
            return right - startPos;
        }
        if (right <= startPos) {
            return startPos - left;
        }
        return min(startPos - left + right - left, right - startPos + right - left);
    }
};
// Time : O(n)
// Space : O(1)