class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) { 
            int mid = left + (right-left)/2;
            if (isFeasible(piles, h, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isFeasible(vector<int>& piles, int& h, int speed) {
        int result = 0;
        for (int i=0; i<piles.size(); ++i) {
            result += (piles[i] / speed + (piles[i] % speed != 0));
            if (result > h) {
                return false;
            }
        }
        return true;
    }
};