class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        vector<int> count(nums.size(), 0);
        for (int i=0; i<n; ++i) {
            arr.push_back({nums[i], i});
        }
        
        mergeSort(arr, count, 0, n - 1);
        return count;
    }
    
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
    
    void merge(vector<pair<int, int>>& arr, vector<int>& count, int left, int mid, int right) {
        int left_ptr = left;
        int right_ptr = mid + 1;
        int temp_ptr = 0;
        vector<pair<int, int>> temp(right - left + 1);
        while (left_ptr <= mid && right_ptr <= right) {
            if (arr[left_ptr].first > arr[right_ptr].first) {
                count[arr[left_ptr].second] += (right - right_ptr + 1);
                temp[temp_ptr] = arr[left_ptr];
                temp_ptr ++;
                left_ptr ++;
            } else {
                temp[temp_ptr] = arr[right_ptr];
                temp_ptr ++;
                right_ptr ++;
            }
        }
        while (left_ptr <= mid) {
            temp[temp_ptr] = arr[left_ptr];
            temp_ptr ++;
            left_ptr ++;
        }
        while (right_ptr <= right) {
            temp[temp_ptr] = arr[right_ptr];
            temp_ptr ++;
            right_ptr ++;
        }
        
        for (int i=left; i<=right; ++i) {
            arr[i] = temp[i - left];
        }
    }
};
// Time : O(nlogn)
// Space : O(n)