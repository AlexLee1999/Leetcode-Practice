class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        if (currentState.size() < 2) {
            return {};
        }
        vector<string> ans;
        for (int i=1; i<currentState.size(); ++i) {
            if (currentState[i - 1] == '+' && currentState[i] == '+') {
                string newState = currentState;
                newState[i - 1] = '-';
                newState[i] = '-';
                ans.push_back(newState);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)