class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        int n = garbage.size();
        int glass_idx = -1;
        int paper_idx = -1;
        int metal_idx = -1;
        vector<unordered_map<char, int>> arr(n);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<garbage[i].size(); ++j) {
                arr[i][garbage[i][j]] ++;
                if (garbage[i][j] == 'G') {
                    glass_idx = i;
                } else if (garbage[i][j] == 'M') {
                    metal_idx = i;
                } else {
                    paper_idx = i;
                }
            }
        }
        if (glass_idx != -1) {
            for (int i=0; i<=glass_idx; ++i) {
                time += arr[i]['G'];
                if (i < glass_idx) {
                    time += travel[i];
                }
            }
        }
        if (metal_idx != -1) {
            for (int i=0; i<=metal_idx; ++i) {
                time += arr[i]['M'];
                if (i < metal_idx) {
                    time += travel[i];
                }
            }
        }
        if (paper_idx != -1) {
            for (int i=0; i<=paper_idx; ++i) {
                time += arr[i]['P'];
                if (i < paper_idx) {
                    time += travel[i];
                }
            }
        }
        return time;
    }
};