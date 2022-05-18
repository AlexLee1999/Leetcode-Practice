class Solution {
public:
    double distance(int x, int y) {
        return sqrt(pow(float(x), 2) + pow(float(y), 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> myHeap;
        for (int i=0; i<points.size(); ++i) {
            myHeap.push({distance(points[i][0], points[i][1]), {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        for (int i=0; i<k; ++i) {
            pair<double, pair<int, int>> tmp = myHeap.top();
            ans.push_back({tmp.second.first, tmp.second.second});
            myHeap.pop();
        }
        return ans;
    }
};