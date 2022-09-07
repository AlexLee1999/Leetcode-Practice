class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> myMap;
        int mod = 1e9 + 7;
        int num = 1;
        vector<int> power = {1};
        for (int i=0; i<21; ++i) {
            num *= 2;
            power.push_back(num);
        }
        long long count = 0;
        
        for (int i=0; i<deliciousness.size(); ++i) {
            for (int j=0; j<power.size(); ++j) {
                if (myMap.count(power[j] - deliciousness[i])) {
                    count += myMap[power[j] - deliciousness[i]];
                    count %= mod;
                }
            }
            myMap[deliciousness[i]] ++;
        }
        count %= mod;
        return count;
    }
};
// Time : O(n)
// Space : O(n)