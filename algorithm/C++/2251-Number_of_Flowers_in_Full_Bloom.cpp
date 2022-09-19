class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        unordered_map<int, int> start;
        unordered_map<int, int> end;
        unordered_map<int, vector<int>> myMap;
        set<int> days;
        int max_day = 0;
        for (int i=0; i<persons.size(); ++i) {
            myMap[persons[i]].push_back(i);
            max_day = max(max_day, persons[i]);
            days.insert(persons[i]);
        }
        
        for (int i=0; i<flowers.size(); ++i) {
            max_day = max(max_day, flowers[i][1]);
            start[flowers[i][0]] ++;
            end[flowers[i][1]] ++;
            days.insert(flowers[i][0]);
            days.insert(flowers[i][1]);
        }
        int num = 0;
        vector<int> ans(persons.size(), 0);
        for (auto it=days.begin(); it != days.end(); ++it) {
            if (start.count(*it)) {
                num += start[*it];
            }
            if (myMap.count(*it)) {
                for (int j=0; j<myMap[*it].size(); ++j) {
                    ans[myMap[*it][j]] = num;
                }
            }
            if (end.count(*it)) {
                num -= end[*it];
            }
        }
        return ans;
    }
};
// Time : O(n + m)
// Space : O(n + m)