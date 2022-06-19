class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (num / mid >= mid){ //find the number less than sqrt(num)
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return (left - 1) * (left - 1) == num;
    }
};
