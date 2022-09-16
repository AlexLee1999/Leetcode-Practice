class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> myMap;
        int n = keyName.size();
        for (int i=0; i<n; ++i) {
            int hour = stoi(keyTime[i].substr(0, 2));
            int min = stoi(keyTime[i].substr(3, 2));
            int total_time = hour * 60 + min;
            myMap[keyName[i]].push_back(total_time);
        }
        vector<string> ans;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            for (int i=2; i<it->second.size(); ++i) {
                if (it->second[i - 2] + 60 >= it->second[i]) {
                    ans.push_back(it->first);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// Time : O(n*klogk)
// Space : O(n)