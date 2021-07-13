class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int low = 1;
        int high = x/2;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mid <= x / mid){
                low = mid + 1; //if equal 
            }
            else{
                high = mid - 1;
            }
        }
        return low - 1;//if terminates, right = low-1 will point to the number n => n*n<=x, 
    }
};