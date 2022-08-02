class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        vector<int> table(arr.size(), (int)1e9 + 1);
        unordered_map<int, int> myMap;
        for (int i=0; i<target.size(); ++i) {
            myMap[target[i]] = i;
        }
        for (int i=0; i<arr.size(); ++i) {
            if (myMap.find(arr[i]) != myMap.end()) {
                table[i] = myMap[arr[i]];
            }
        }
        vector<int> subsequence;
        for (int i=0; i<table.size(); ++i) {
            if (table[i] == (int)1e9 + 1) {
                continue;
            }
            auto it = lower_bound(subsequence.begin(), subsequence.end(), table[i]);
            if (it == subsequence.end()) {
                subsequence.push_back(table[i]);
            } else {
                *it = table[i];
            }
        }
        return target.size() - subsequence.size();
    }
};
// Time : O(nlogn)
// Space : O(n)
// convert arr into the index of target if the element is in target
// Find the Longest increasing subsequence 