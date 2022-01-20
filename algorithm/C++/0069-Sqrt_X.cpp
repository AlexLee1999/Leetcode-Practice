class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int low = 1;
        int high = x;
        while (low < high){
            long long mid = low + (high - low) / 2;
            long long ans = mid*mid;
            if (ans > x){
                high = mid;
            }
            else if (ans <= x) {
                low = mid + 1;
            }
        }
        return low - 1; //low = the smallest number that low*low > x;
    }
};
