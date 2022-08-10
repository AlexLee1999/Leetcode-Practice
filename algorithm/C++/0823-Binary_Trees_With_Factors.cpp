class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> myMap;
        sort(arr.begin(), arr.end());
        int mod = 1e9 + 7;
        for (int i=0; i<arr.size(); ++i) {
            myMap[arr[i]] = i;
        }
        vector<long long> table(arr.size(), 1);
        for (int i=0; i<arr.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    if (myMap.find(arr[i] / arr[j]) != myMap.end()) {
                        table[i] = (table[i] + (table[j] * table[myMap[arr[i] / arr[j]]]) % mod) % mod;
                    }
                }
            }
            
        }
        int ans = 0;
        for (int i=0; i<arr.size(); ++i) {
            ans = (ans + table[i]) % mod;
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n)