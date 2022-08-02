class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> vec(arr.size());
        int ptr = 0;
        for (int i=0; i<arr.size(); ++i) {
            vec[ptr] = {countBits(arr[i]), arr[i]};
            ptr ++;
        }
        sort(vec.begin(), vec.end());
        for (int i=0; i<arr.size(); ++i) {
            arr[i] = vec[i].second;
        }
        return arr;
    }
    int countBits(int x) {
        int count = 0;
        while (x > 0) {
            count += (x & 1);
            x >>= 1;
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(n)