class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        long int right = (long int)sqrt(c);
        while(left <=right){
            long int square = left*left + right*right;
            if(square > c){
                --right;
            }
            else if(square < c){
                ++left;
            }
            else{
                return true;
            }
        }
        return false;
    }
};