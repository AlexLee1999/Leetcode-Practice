class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total_tank = 0;
        int current_tank = 0;
        for (int i=0; i<gas.size(); ++i) {
            total_tank += (gas[i] - cost[i]);
            current_tank += (gas[i] - cost[i]); 
            if (current_tank < 0) { //check that start from "start" is feasible
                start = i + 1;
                current_tank = 0;
            }
        }
        return total_tank >= 0 ? start : -1;
    }
};