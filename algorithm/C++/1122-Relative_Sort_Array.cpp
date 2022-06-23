class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> mySet2(arr2.begin(), arr2.end());
        unordered_map<int, int> myMap;
        vector<int> exclusive;
        vector<int> res;
        for (int i=0; i<arr1.size(); ++i) {
            if(mySet2.count(arr1[i])) {
                myMap[arr1[i]] ++;
            }
            else {
                exclusive.push_back(arr1[i]);
            }
        }
        sort(exclusive.begin(), exclusive.end());
        for (int i=0; i<arr2.size(); ++i) {
            for (int j=0; j<myMap[arr2[i]]; ++j) {
                res.push_back(arr2[i]);
            }
        }
        for (int i=0; i<exclusive.size(); ++i) {
            res.push_back(exclusive[i]);
        }
        return res;
    }
};
// Time : O(nlogn)
// Space : O(n)