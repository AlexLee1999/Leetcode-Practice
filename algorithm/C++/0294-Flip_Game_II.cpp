class Solution {
public:
    bool canWin(string currentState) {
        unordered_map<string, bool> myMap;
        if (currentState.size() < 2) {
            return false;
        }
        return dfs(currentState, myMap);
    }
    bool dfs(string currentState, unordered_map<string, bool>& myMap) {
        if (myMap.count(currentState)) {
            return myMap[currentState];
        }
        for (int i=1; i<currentState.size(); ++i) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                string newState = currentState;
                newState[i] = '-';
                newState[i - 1] = '-';
                if (!dfs(newState, myMap)) {
                    myMap[currentState] = true;
                    return true;
                }
            }
        }
        myMap[currentState] = false;
        return false;
    }
};
// Time : O(2^(N))
// Space : O(2^(N))