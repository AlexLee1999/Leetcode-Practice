class Solution {
public:
    string interpret(string command) {
        string s = "";
        int i = 0;
        while (i < command.size()) {
            if (command[i] == 'G') {
                s += 'G';
                i ++;
            } else if (command.substr(i, 4) == "(al)") {
                s += "al";
                i += 4;
            } else if (command.substr(i, 2) == "()") {
                s += 'o';
                i += 2;
            }
        }
        return s;
    }
};
// Time : O(n)
// Space : O(1)