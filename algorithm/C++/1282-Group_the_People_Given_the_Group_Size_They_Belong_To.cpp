class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> myMap;
        for (int i=0; i<groupSizes.size(); ++i) {
            myMap[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            
            int group_num = it->second.size() / it->first;
            int ptr = 0;
            for (int i=0; i<group_num; ++i) {
                vector<int> tmp;
                for (int j=0; j<it->first; ++j) {
                    tmp.push_back(it->second[ptr]);
                    ptr ++;
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)