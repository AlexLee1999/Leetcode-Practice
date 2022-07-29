class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> myMap;
        unordered_set<string> mySet;
        for (int i=0; i<regions.size(); ++i) {
            for (int j=1; j<regions[i].size(); ++j) {
                myMap[regions[i][j]] = regions[i][0];
            }
        }
        mySet.insert(region1);
        while (myMap.find(region1) != myMap.end()) {
            region1 = myMap[region1];
            mySet.insert(region1);
        }
        while (!mySet.count(region2)) {
            region2 = myMap[region2];
        }
        return region2;
    }
};
// Time : O(N)
// Space : O(N)