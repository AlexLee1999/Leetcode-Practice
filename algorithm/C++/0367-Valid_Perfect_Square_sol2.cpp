class Solution {
public:
    bool isPerfectSquare(int num) {
        int right = num;
        int left = 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = mid;
            square *= mid;
            if (square == num) { 
                return true;
            }
            else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};