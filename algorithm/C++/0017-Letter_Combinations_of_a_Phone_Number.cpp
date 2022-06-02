class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> myMap;
        myMap['2'] = {'a', 'b', 'c'};
        myMap['3'] = {'d', 'e', 'f'};
        myMap['4'] = {'g', 'h', 'i'};
        myMap['5'] = {'j', 'k', 'l'};
        myMap['6'] = {'m', 'n', 'o'};
        myMap['7'] = {'p', 'q', 'r', 's'};
        myMap['8'] = {'t', 'u', 'v'};
        myMap['9'] = {'w', 'x', 'y', 'z'};
        queue<string> myQueue;
        if (digits == "") {
            return vector<string>();
        }
        myQueue.push("");
        backtrack(myQueue, myMap, digits, 0);
        vector<string> res;
        while(!myQueue.empty()){
            res.push_back(myQueue.front());
            myQueue.pop();
        }
        return res;
    }
    void backtrack(queue<string>& myQueue, unordered_map<char, vector<char>>& myMap, string& digits, int index) {
        if (index == digits.size()) {
            return;
        }
        int size = myQueue.size();
        for (int i=0; i<size; ++i) {
            for(int j=0; j<myMap[digits[index]].size(); ++j) {
                myQueue.push(myQueue.front() + myMap[digits[index]][j]);
            }
            myQueue.pop();
        }
        backtrack(myQueue, myMap, digits, index + 1);
    }
};