class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    
        vector<int> count(101, 0);
        for (int i=0; i<logs.size(); ++i) {
            count[logs[i][0] - 1950] ++;
            count[logs[i][1] - 1950] --;
        }
        int num = 0;
        int ans = 0;
        int max_num = 0;
        for (int i=0; i < 101; ++i) {
            num += count[i];
            if (num > max_num) {
                max_num = num;
                ans = i + 1950;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)