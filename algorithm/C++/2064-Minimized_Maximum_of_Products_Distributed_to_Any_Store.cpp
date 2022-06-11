class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(n, quantities, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(int n, vector<int>& quantities, int num) {
        int count = 0;
        for (int i=0; i<quantities.size(); ++i) {
            count += ceil((float)quantities[i] / (float)num);
            if (count > n) {
                return false;
            }
        }
        return count <= n;
    }
};