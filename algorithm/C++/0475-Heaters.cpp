class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0;
        int right = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(houses, heaters, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& houses, vector<int>& heaters, int rad) {
        int i = 0;
        int j = 0;
        while (i < houses.size()) {
            if (j == heaters.size()) {
                return false;
            }
            int left = heaters[j] - rad;
            int right = heaters[j] + rad;
            if (left > houses[i] || right < houses[i]) {
                j ++;
            } else {
                i ++;
            }
        }
        return true;
    }
};