class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i=0; i<image.size(); ++i) {
            reverse(image[i].begin(), image[i].end());
            for (int j=0; j<image[i].size(); ++j) {
                image[i][j] ^= 1;
            }
        }
        return image;
    }
};
// Time : O(N) N is the number of elements
// Space : O(1)