class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> complex_1 = decode(num1);
        pair<int, int> complex_2 = decode(num2);
        int first = (complex_1.first * complex_2.first) - (complex_1.second * complex_2.second);
        int second = (complex_1.first * complex_2.second) + (complex_1.second * complex_2.first);
        return to_string(first) + '+' + to_string(second) + 'i';
    }
    pair<int, int> decode(string s) {
        pair<int, int> complex;
        int plus_pos = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '+') {
                string first = s.substr(0, i);
                complex.first = stoi(first);
                plus_pos = i;
            } else if (s[i] == 'i') {
                string second = s.substr(plus_pos + 1, s.size() - 1 - plus_pos);
                complex.second = stoi(second);
            }
        }
        return complex;
    }
};
// Time : O(1)
// Space : O(1)