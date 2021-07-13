class Solution {
public:
    bool isUgly(int n) {
        if(n == 0){
            return false;
        }
        while(n != 1){
            if((n & 1) == 0){
                n = n >> 1;
            }
            else if(n % 3 == 0){
                n /= 3;
            }
            else if(n % 5 == 0){
                n /= 5;
            }
            else{
                return false;
            }
        }
        return true;
    }
};