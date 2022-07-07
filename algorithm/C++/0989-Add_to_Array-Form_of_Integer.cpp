class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int sum = 0;
        for (int i=num.size() - 1; i >= 0; --i) {
            sum += num[i] +  k % 10;
            k /= 10;
            num[i] = sum % 10;
            sum /= 10;
        }
        while (k > 0 || sum > 0) {
            sum += k % 10;
            k /= 10;
            
            num.insert(num.begin(), sum % 10);
            sum /= 10;
        }
        return num;
    }
};
// Time : O(n + logk)
// Space : O(1)