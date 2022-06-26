class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        vector<int> count;
        for (int i=0; i<nums.size(); ++i) {
            myMap[nums[i]] ++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            count.push_back(it->first);
        }
        quickselect(myMap, count, 0, count.size() - 1, k);
        return vector<int>(count.begin() + count.size() - k, count.end());
    }
    void quickselect(unordered_map<int, int>& myMap, vector<int>& count, int low, int high, int k) {
        if (low < high) {
            int pivot = partition(myMap, count, low, high);
            if (pivot == count.size() - k) {
                return;
            } else if (pivot > count.size() - k) {
                quickselect(myMap, count, low, pivot - 1, k);
            } else {
                quickselect(myMap, count, pivot + 1, high, k);
            }
        }
    }
    int partition(unordered_map<int, int>& myMap, vector<int>& count, int low, int high) {
        int pivot = myMap[count[high]];
        int idx = low - 1;
        for (int i=low; i<high; ++i) {
            if (myMap[count[i]] <= pivot) {
                idx ++;
                swap(count[idx], count[i]);
            }
        }
        swap(count[high], count[idx + 1]);
        return idx + 1;
    }
};
// Time : O(n)
// Space : O(n)