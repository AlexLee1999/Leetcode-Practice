class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> table(n + 1, 0);
        for (int i=1; i<=n; ++i) {
            table[i] = table[i-1] + books[i-1][1]; // add an new layer 
            int width = books[i-1][0];
            int height = books[i-1][1];
            for (int j=i-2; j >= 0 && width + books[j][0] <= shelfWidth; --j) { // find previous books and add them to the current layer
                height = max(height, books[j][1]);
                width += books[j][0];
                table[i] = min(table[i], table[j] + height);
            }
        }
        return table[n];
    }
};
// Time : O(n^2)
// Space : O(n)