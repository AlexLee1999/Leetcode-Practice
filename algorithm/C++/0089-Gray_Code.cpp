class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> results = {0};
        for (int i=0; i<n; ++i) {
            int mask = 1 << i;
            int size = results.size();
            for (int j=size-1; j >=0; j--) {
                results.push_back(results[j] + mask);
            }
        }
        return results;
    } 
};