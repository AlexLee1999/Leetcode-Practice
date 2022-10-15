class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> myMap;
        myMap[1] = 0;
        vector<pair<int, int>> arr;
        for (int i=lo; i<=hi; ++i) {
            arr.push_back({power(i, myMap), i});
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1].second;
    }
    int power(int n, unordered_map<int, int>& myMap) {
        if (myMap.count(n)) {
            return myMap[n];
        }
        if (n % 2 == 1) {
            myMap[n] = power(3 * n + 1, myMap) + 1;
            return myMap[n];
        }
        myMap[n] = power(n / 2, myMap) + 1;
        return myMap[n];
    }
};