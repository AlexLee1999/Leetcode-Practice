class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> results;
        for (int i=0; i<=rowIndex; ++i) {
            results.push_back(Cfunction(rowIndex, i));
        }
        return results;
    }
    int Cfunction(int n, int k) {
        long long result = 1;
        for (int i=k+1; i<=n; ++i) {
            result *= i;
            result /= (i-k);
        }
        return result;
    }
};