class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> encodeWords;
        int n = words.size();
        for (int i=0; i<words.size(); ++i) {
            int num = 0;
            for (int j=0; j<words[i].size(); ++j) {
                num |= 1 << (words[i][j] - 'a');
            }
            encodeWords.push_back(num);
        }
        int max_len = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if ((encodeWords[j] & encodeWords[i]) == 0) {
                    int prod = words[i].size() * words[j].size();
                    max_len = max(max_len, prod);
                }
            }
        }
        return max_len;
    }
};