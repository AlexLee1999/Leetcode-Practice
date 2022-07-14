class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> event(difficulty.size(), pair<int, int>());
        for (int i=0; i<difficulty.size(); ++i) {
            event[i] = {difficulty[i], profit[i]};
        }
        sort(event.begin(), event.end());
        sort(worker.begin(), worker.end());

        int j = 0;
        int total_profit = 0;
        int cur_max = 0;
        for (int i=0; i<worker.size(); ++i) {
            while (j < event.size() && worker[i] >= event[j].first) {
                cur_max = max(cur_max, event[j].second);
                j ++;
            }
            total_profit += cur_max;
        }
        return total_profit;
    }
};
// Time : O(nlogn + mlogm)
// Space : O(n)
/* Idea : sort the ability of workers and the difficulty of the tasks.
From the first worker, try to calculate the most profitable work within its ability*/ 