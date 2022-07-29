class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int ptr1 = 0;
        int ptr2 = 0;
        int ptr3 = 0;
        while (ptr1 < arr1.size() && ptr2 < arr2.size() && ptr3 < arr3.size()) {
            if (arr1[ptr1] == arr2[ptr2] && arr2[ptr2] == arr3[ptr3]) {
                ans.push_back(arr1[ptr1]);
                ptr1 ++;
                ptr2 ++;
                ptr3 ++;
                continue;
            }
            int m = min(arr1[ptr1], min(arr2[ptr2], arr3[ptr3]));
            if (m == arr1[ptr1]) {
                ptr1 ++;
            } else if (m == arr2[ptr2]) {
                ptr2 ++;
            } else {
                ptr3 ++;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)