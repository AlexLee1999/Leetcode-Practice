class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> myMap;
        for (int i=0; i<pieces.size(); ++i) {
            myMap[pieces[i][0]] = pieces[i];
        }
        int i = 0;
        while (i < arr.size()) {
            if (myMap.count(arr[i]) == 0) {
                return false;
            }
            int j = 0;
            int ptr = i;
            while (j < myMap[arr[ptr]].size()) {
                if (arr[i] != myMap[arr[ptr]][j]) {
                    return false;
                }
                i ++;
                j ++;
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(n)