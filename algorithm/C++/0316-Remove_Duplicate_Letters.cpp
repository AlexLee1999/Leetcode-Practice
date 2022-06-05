class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> mySet;
        unordered_map<char, int> myMap;
        stack<char> myStack;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] = i;
        }
        for (int i=0; i<s.size(); ++i) {
            if (mySet.find(s[i]) == mySet.end()) {
                while (!myStack.empty() && s[i] < myStack.top() && myMap[myStack.top()] > i) {//if myStack.top is larger than s[i] and myStack.top will occur later
                    mySet.erase(myStack.top());
                    myStack.pop();
                }
                myStack.push(s[i]);
                mySet.insert(s[i]);
            }
        }
        string ans = "";
        while (!myStack.empty()) {
            ans = myStack.top() + ans;
            myStack.pop();
        }
        return ans;
    }
};