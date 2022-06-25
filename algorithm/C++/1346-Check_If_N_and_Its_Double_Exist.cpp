class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> mySet(arr.begin(), arr.end());
        int count = 0;
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i] == 0) {
                count ++;
            }
        }
        if (count >= 2) {
            return true;
        }
        for (int i=0; i<arr.size(); ++i) {
            if (mySet.count(arr[i] * 2) && arr[i] != 0) {
                return true;
            } 
        }
        return false;
    } 
};
// Time : O(n)
// Space : O(n)