class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> myMap;
        for (int i=0; i<changed.size(); ++i) {
            myMap[changed[i]] ++;
        }
        int target = changed.size() / 2;
        if (changed.size() % 2 == 1) {
            return {};
        } 
        sort(changed.begin(), changed.end());
        vector<int> ans;
        for (int i=0; i<changed.size(); ++i) {
            if (changed[i] != 0) {
                int single = changed[i];
                int dou = 2 * changed[i];
                if (myMap[single] > 0 && myMap[dou] > 0) {
                    for (int j=0; j<min(myMap[dou], myMap[single]); ++j) {
                        ans.push_back(changed[i]);
                    }
                    int minus = min(myMap[dou], myMap[single]);
                    myMap[single] -= minus;
                    myMap[dou] -= minus;
                }
            } else {
                if (myMap[0] % 2 == 0) {
                    for (int j=0; j<myMap[0]/2; ++j) {
                        ans.push_back(changed[i]);
                    }
                    myMap.erase(changed[i]);
                }
            }
            
        }
        if (ans.size() < target) {
            return {};
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)