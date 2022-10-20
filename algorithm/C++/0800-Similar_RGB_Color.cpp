class Solution {
public:
    string similarRGB(string color) {
        for (int i = 1; i < color.size(); i += 2) {
            int num = stoi(color.substr(i, 2), nullptr, 16);
            int idx = num / 17 + (num % 17 > 8 ? 1 : 0);
            color[i] = color[i + 1] = (idx > 9) ? (idx - 10 + 'a') : (idx + '0');
        }
        return color;
    }
};
// Time : O(1)
// Space : O(1)