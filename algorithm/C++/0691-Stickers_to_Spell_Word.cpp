class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        queue<vector<int>> myQueue;
        vector<vector<int>> count(stickers.size(), vector<int>(26, 0));
        for (int i=0; i<stickers.size(); ++i) {
            for (int j=0; j<stickers[i].size(); ++j) {
                count[i][stickers[i][j] - 'a'] ++;
            }
        }
        vector<int> target_count(26, 0);
        for (int i=0; i<target.size(); ++i) {
            target_count[target[i] - 'a'] ++;
        }
        myQueue.push(target_count);
        int step = 0;
        set<vector<int>> visited;
        visited.insert(target_count);
        while(!myQueue.empty()) {
            int size = myQueue.size();
            if (step >= target.size()) {
                return -1;
            }
            for (int i=0; i<size; ++i) {
                vector<int> front = myQueue.front();
                myQueue.pop();
                if (checkAllZero(front)) {
                    return step;
                }
                for (int j=0; j<stickers.size(); ++j) {
                    vector<int> tmp(26, 0);
                    for (int k=0; k<26; ++k) {
                        tmp[k] = max(0, front[k] - count[j][k]);
                    }
                    if (!visited.count(tmp)) {
                        myQueue.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    bool checkAllZero(vector<int>& arr) {
        for (int i=0; i<26; ++i) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(S^2 + 2^T * S)
// Space : O(2^T)