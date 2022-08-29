class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loses;
        vector<int> lose_player;
        vector<int> win_player;
        for (int i=0; i<matches.size(); ++i) {
            if (!loses.count(matches[i][0])) {
                loses[matches[i][0]] = 0;
            }            
            loses[matches[i][1]] ++;
        }
        for (auto it = loses.begin(); it != loses.end(); ++it) {
            if (it->second == 0) {
                win_player.push_back(it->first);
            }
            if (it->second == 1) {
                lose_player.push_back(it->first);
            }
        }
        return {win_player, lose_player};
    }
};
// Time : O(n + m)
// Space : O(n + m)