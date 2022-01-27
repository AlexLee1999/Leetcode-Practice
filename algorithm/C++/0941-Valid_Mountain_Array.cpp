class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool decrease = false;
        bool increase = false;
        for (int i=1; i<arr.size(); ++i) {
            if (arr[i-1] < arr[i] && !increase) {
                increase = true;
                continue;
            } else if (arr[i-1] < arr[i] && decrease) {
                return false;
            } else if (arr[i-1] == arr[i]) {
                return false;
            } else if (arr[i-1] > arr[i] && !decrease && increase) {
                decrease = true;
            } else if (arr[i-1] > arr[i] && !increase) {
                return false;
            }
        }
        return increase && decrease;
    }
};