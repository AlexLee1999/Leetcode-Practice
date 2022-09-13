class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while (i < data.size()) {
            if (getBit(data[i], 7) == 0) {
                i ++;
            } else if (getBit(data[i], 7) == 1 && getBit(data[i], 6) == 1 && getBit(data[i], 5) == 0) {
                if (i + 1 >= data.size()) {
                    return false;
                }
                if (getBit(data[i + 1], 7) != 1 || getBit(data[i + 1], 6) != 0) {
                    return false;
                }
                i += 2;
            } else if (getBit(data[i], 7) == 1 && getBit(data[i], 6) == 1 && getBit(data[i], 5) == 1 && getBit(data[i], 4) == 0) {
                if (i + 2 >= data.size()) {
                    return false;
                }
                if (getBit(data[i + 1], 7) != 1 || getBit(data[i + 1], 6) != 0) {
                    return false;
                }
                if (getBit(data[i + 2], 7) != 1 || getBit(data[i + 2], 6) != 0) {
                    return false;
                }
                i += 3;
            } else if (getBit(data[i], 7) == 1 && getBit(data[i], 6) == 1 && getBit(data[i], 5) == 1 && getBit(data[i], 4) == 1 && getBit(data[i], 3) == 0) {
                if (i + 3 >= data.size()) {
                    return false;
                }
                if (getBit(data[i + 1], 7) != 1 || getBit(data[i + 1], 6) != 0) {
                    return false;
                }
                if (getBit(data[i + 2], 7) != 1 || getBit(data[i + 2], 6) != 0) {
                    return false;
                }
                if (getBit(data[i + 3], 7) != 1 || getBit(data[i + 3], 6) != 0) {
                    return false;
                }
                i += 4;
            } else {
                return false;
            }
        }
        return true;
    }
    int getBit(int num, int bit_pos) {
        return (num & (1 << bit_pos)) >> bit_pos;
    }
};
// Time : O(n)
// Space : O(1)