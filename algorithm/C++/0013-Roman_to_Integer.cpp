class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> myMap;
        myMap["M"] = 1000;
        myMap["CM"] = 900;
        myMap["D"] = 500;
        myMap["CD"] = 400;
        myMap["C"] = 100;
        myMap["XC"] = 90;
        myMap["L"] = 50;
        myMap["XL"] = 40;
        myMap["X"] = 10;
        myMap["IX"] = 9;
        myMap["V"] = 5;
        myMap["IV"] = 4;
        myMap["I"] = 1;
        
        int num = 0;
        int i = 0;
        while (i < s.size()) {
            if (i != s.size() - 1) {
                string s2 = s.substr(i, 2);
                if (myMap.find(s2) != myMap.end()) {
                    num += myMap[s2];
                    i += 2;
                } else {
                    num += myMap[s.substr(i, 1)];
                    i ++;
                }
            } else {
                num += myMap[s.substr(i, 1)];
                i ++;
            }
        }
        return num;
    }
};
// Time : O(1)
// Space : O(1)