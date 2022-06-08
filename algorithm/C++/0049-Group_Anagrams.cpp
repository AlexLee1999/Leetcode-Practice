class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> my_map;
        for (int i=0; i<strs.size(); ++i) {
            string temp_str = strs[i];
            sort(temp_str.begin(), temp_str.end());
            my_map[temp_str].push_back(strs[i]);
        }
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            results.push_back(it->second);
        }
        return results;
    }
};
// Time : O(nklogk) k is the longest string, n is the size of strs
// Space : O(nk)