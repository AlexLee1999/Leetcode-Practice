class Solution {
public:
    Solution(vector<int>& w) {
        sum = 0;
        prefix = vector<int>(w.size(), 0);
        for (int i=0; i<w.size(); ++i) {
            sum += w[i];
            prefix[i] = sum;
        }
    }
    
    int pickIndex() {
        int ran = rand() % sum;
        int left = 0;
        int right = prefix.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] <= ran) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
private:
    vector<int> prefix;
    int sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// Time : O(n + logn)
// Space : O(n)