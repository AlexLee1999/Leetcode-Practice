class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> results;
        for (int i=1; i<=9; ++i) {
            int num = i;
            for (int j=i+1; j<=9; ++j) {
                num *= 10;
                num += j;
                if (low <= num && num <= high) {
                    results.push_back(num);
                }
            }
        }
        sort(results.begin(), results.end());
        return results;
    }
};