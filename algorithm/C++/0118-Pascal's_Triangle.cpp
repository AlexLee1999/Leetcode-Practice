class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results = {{1}};
        for (int i=1; i<numRows; ++i) {
            vector<int> current_result;
            for (int j=0; j<=i; ++j) {
                if (j == 0) {
                    current_result.push_back(1);
                } else if (j == i) {
                    current_result.push_back(1);
                } else {
                    current_result.push_back(results[i-1][j-1]+results[i-1][j]);
                }
            }
            results.push_back(current_result);
        }
        return results;
    }
};