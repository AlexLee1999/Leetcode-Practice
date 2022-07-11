class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int total = 0;
        int max_diff = INT_MIN;
        for (int i=0; i<nuts.size(); ++i) {
            total += 2 * distance(nuts[i], tree);
            max_diff = max(max_diff, distance(nuts[i], tree) - distance(nuts[i], squirrel)); 
            // find the maximum difference between nuts to tree and nuts to squirrel
        }
        return total - max_diff;
    }
    int distance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
// Time : O(n)
// Space : O(1)