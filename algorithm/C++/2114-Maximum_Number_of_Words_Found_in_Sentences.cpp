class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_num = 0;
        
        for (int i=0; i<sentences.size(); ++i) {
            int num = 0;
            for (int j=0; j<sentences[i].size(); ++j) {
                if (sentences[i][j] == ' ') {
                    num ++;
                }
            }
            max_num = max(max_num, num + 1);
        }
        return max_num;
    }
};
// Time : O(mn)
// Space : O(1)