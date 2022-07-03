class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long hor = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i=0; i<horizontalCuts.size() - 1; ++i) {
            hor = max(hor, (long long)horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        
        long long ver = max(verticalCuts[0], w - verticalCuts.back());
        for (int i=0; i<verticalCuts.size() - 1; ++i) {
            ver = max(ver, (long long)verticalCuts[i + 1] - verticalCuts[i]);
        }
        
        return (int) (((ver) * (hor)) % 1000000007);
    }
};
// Time : O(nlogn + mlogm)
// Space : O(1)