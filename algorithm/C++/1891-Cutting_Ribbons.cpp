class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        long long total = 0;
        int max_num = 0;
        for (int i=0; i<ribbons.size(); ++i) {
            total += ribbons[i];
            max_num = max(max_num, ribbons[i]);
        }
        if (total < k) {
            return 0;
        }
        
        int left = 1;
        int right = max_num;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCut(ribbons, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool canCut(vector<int>& ribbons, int k, int len) {
        int count = 0;
        for (int i=0; i<ribbons.size(); ++i) {
            count += (ribbons[i] / len);
            if (count >= k) {
                return true;
            }
        }
        return false;
    }
};
// Time : O(nlogk)
// Space : O(1)