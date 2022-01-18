class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 1;
        for (int i=0; i<flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                count ++;
            
                if (count == 3) {
                    count = 1;
                    --n;
                }
            } else {
                count = 0;
            }
            if (n == 0) {
                return true;
            }
        }
        if (count == 2) {
            --n;
        }
        return n == 0;
    }
};