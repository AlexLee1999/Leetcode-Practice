class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> days_set(days.begin(), days.end());
        int last_day = days.back();
        vector<int> table(last_day + 1, 0);
        
        for (int i=1; i<=last_day; ++i) {
            if (days_set.count(i)) {// If need tickets
                table[i] = table[max(0, i - 1)] + costs[0]; // Option1 : buy 1 day
                table[i] = min(table[i], table[max(0, i - 7)] + costs[1]); // Option2 : buy 7 day
                table[i] = min(table[i], table[max(0, i - 30)] + costs[2]); // Option3 : buy 30 day
            } else {
                table[i] = table[i - 1];
            }
            
        }
        return table[last_day];
    }
};
// Time : O(D)
// Space : O(D)