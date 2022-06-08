class Solution {
public:
    int minSwaps(vector<int>& data) {
        int one_num = 0;
        for (int i=0; i<data.size(); ++i) {
            one_num += data[i];
        }
        int left = 0;
        int right = 0;
        int cur = 0;
        int max_one = 0;
        for (right=0; right < data.size(); ++right) {
            cur += data[right];
            while (right - left >= one_num) {
                cur -= data[left];
                left ++;
            }
            max_one = max(max_one, cur);
        }
        return one_num - max_one;
    }
};
// Time : O(n)
// Space : O(1)