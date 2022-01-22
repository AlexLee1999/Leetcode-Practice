class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result = {0};
        while (true) {
            int size = result.size();
            for (int i=0; i<size; ++i) {
                if (n > 0) {
                    result.push_back(result[i] + 1);
                    n --;
                }
            }
            if (n <= 0) {
                break;
            }
        }
        return result;
    }
};