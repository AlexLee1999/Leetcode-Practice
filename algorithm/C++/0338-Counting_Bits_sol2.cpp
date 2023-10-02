class Solution {
public:
    vector<int> countBits(int n) {
        unordered_set<int> pow;
        for (int i=1; i<32; ++i) {
            pow.insert(1 << i);
        }
        vector<int> arr;
        int mod = 1;
        arr.push_back(0);
        for (int i=1; i<=n; ++i) {
            if (pow.count(i)) {
                mod = i;
            }
            arr.push_back(arr[i % mod] + 1);
        }
        return arr;
    }
};