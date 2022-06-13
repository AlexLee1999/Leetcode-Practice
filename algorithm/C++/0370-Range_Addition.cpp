class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        for (int i=0; i<updates.size(); ++i) {
            int start = updates[i][0];
            int end = updates[i][1];
            int val = updates[i][2];
           res[start] += val;  //arr[i] = arr[i] + val
            if (end < length - 1) {
                res[end + 1] -= val; // arr[i] = arr[i] + val - val 
            }
        }
        for (int i=1; i<length; ++i) {
            res[i] += res[i - 1];
        }
        return res;
    }
};
// Time : O(n)
// Space : O(n)