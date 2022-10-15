class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int minute = targetSeconds / 60;
        int second = targetSeconds % 60;
        int min_cost = INT_MAX;
        if (second < 40 && minute > 0) {
            min_cost = calculateCost(startAt, minute - 1, second + 60, moveCost, pushCost);
        }
        if (minute >= 100) {
            return min_cost;
        }
        return min(min_cost, calculateCost(startAt, minute, second, moveCost, pushCost));
        
    }
    int calculateCost(int start, int m, int s, int moveCost, int pushCost) {
        vector<int> minute_arr;
        vector<int> second_arr;
        int cost = 0;
        while (m > 0) {
            minute_arr.push_back(m % 10);
            m /= 10;
        }
        reverse(minute_arr.begin(), minute_arr.end());
        while (s > 0) {
            second_arr.push_back(s % 10);
            s /= 10;
        }
        if (second_arr.size() == 0) {
            second_arr.push_back(0);
            second_arr.push_back(0);
        } else if (second_arr.size() == 1 && minute_arr.size() != 0) {
            second_arr.push_back(0);
        }
        reverse(second_arr.begin(), second_arr.end());
        int prev = start;
        for (int i=0; i<minute_arr.size(); ++i) {
            if (minute_arr[i] != prev) {
                cost += moveCost;
            }
            cost += pushCost;
            prev = minute_arr[i];
        }
        for (int i=0; i<second_arr.size(); ++i) {
            if (second_arr[i] != prev) {
                cost += moveCost;
            }
            cost += pushCost;
            prev = second_arr[i];
        }
        return cost;
    }
};
// Time : O(1)
// Space : O(1)