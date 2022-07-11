class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int cur_max = -1;
        for (int i=arr.size() - 1; i>= 0; --i) {
            int tmp = arr[i];
            arr[i] = cur_max;
            cur_max = max(cur_max, tmp);
        }
        return arr;
    }
};
// Time : O(n)
// Space : O(1)