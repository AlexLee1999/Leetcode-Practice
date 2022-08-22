class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        int size = arr.size();
        for (int i=0; i<arr.size(); ++i) {
            count[arr[i]] ++;
        }
        vector<int> freq;
        for (auto it=count.begin(); it != count.end(); ++it) {
            freq.push_back(it->second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        int removed = 0;
        for (int i=0; i<freq.size(); ++i) {
            removed += freq[i];
            ans ++;
            if (removed >= size / 2) {
                return ans;
            }
        }
        return -1;
    }
};
// Time : O(m + nlogn)
// Space : O(m + n)