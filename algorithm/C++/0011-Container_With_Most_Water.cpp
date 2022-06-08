class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            if (h * (j - i) > max) {
                max = h * (j - i);
            }
            while (i < j && height[j] <= h) {
                --j;
            }
            while (i < j && height[i] <= h) {
                ++i;
            }
        }
        return max;
    }
};
// Time : O(n)
// Space : O(1)
