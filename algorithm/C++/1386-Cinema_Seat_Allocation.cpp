class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> myMap;
        int count = 0;
        for(int i=0; i<reservedSeats.size(); ++i) {
            myMap[reservedSeats[i][0]] = myMap[reservedSeats[i][0]] | 1 << reservedSeats[i][1];
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            int cur_count = 0;
            if ((it->second & 60) == 0) {
                cur_count += 1;
            }
            if ((it->second & 960) == 0) {
                cur_count += 1;
            }
            if ((it->second & 240) == 0 && cur_count == 0) {
                cur_count += 1;
            }
            count += cur_count;
        }
        return count + (n - myMap.size()) * 2;
    }
};
// Time : O(m)
// Space : O(m)