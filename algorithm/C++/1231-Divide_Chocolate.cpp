class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = *min_element(sweetness.begin(), sweetness.end());
        int sum = 0;
        for (int i=0; i<sweetness.size(); ++i) {
            sum += sweetness[i];
        }
        int right = sum / (k + 1);
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(sweetness, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right; //right = left - 1
    }
    bool isPossible(vector<int>& sweetness, const int& k, const int& sweet) {
        int num = 0;
        int cur_sweet = 0;
        for (int i=0; i<sweetness.size(); ++i) {
            cur_sweet += sweetness[i];
            if (cur_sweet >= sweet) {
                cur_sweet = 0;
                num ++;
            }
            if (num >= k+1) {
                return true;
            }
        }
        return num >= k + 1;
    }
};