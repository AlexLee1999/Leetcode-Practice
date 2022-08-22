class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, int> myMap;
        long long ans = 0;
        for (int i=0; i<rectangles.size(); ++i) {
            int div = gcd(rectangles[i][0], rectangles[i][1]);
            rectangles[i][0] /= div;
            rectangles[i][1] /= div;
            myMap[to_string(rectangles[i][0]) + ',' + to_string(rectangles[i][1])] ++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            ans += (long long)(it->second) * (it->second - 1) / 2;
        }
        return ans;
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
// Time : O(n)
// Space : O(n)