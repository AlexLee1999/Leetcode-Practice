class Solution {
public:
    string intToRoman(int num) {
        vector<string> str = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        for (int i=0; i<str.size(); ++i) {
            while (num >= number[i]) {
                num -= number[i];
                result += str[i];
            }
        }
        return result;
    }
};