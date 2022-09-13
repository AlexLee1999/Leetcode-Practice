class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int cur_size = 0;
        int cur_sum = 0;
        int prev_size = 0;
        int prev_sum = 0;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            cur_sum += grades[i];
            cur_size += 1;
            if (cur_sum > prev_sum && cur_size > prev_size) {
                prev_sum = cur_sum;
                prev_size = cur_size;
                cur_sum = 0;
                cur_size = 0;
                ans ++;
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space ; O(1)