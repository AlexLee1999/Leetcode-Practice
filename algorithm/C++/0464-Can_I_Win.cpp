class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int max_sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (max_sum < desiredTotal) {
            return false;
        }
        unordered_map<int, bool> myMap;
        return dfs(maxChoosableInteger, desiredTotal, myMap, 0);
    }
    bool dfs(int maxChoosableInteger, int desiredTotal, unordered_map<int, bool>& myMap, int curState) {
        if (myMap.count(curState)) {
            return myMap[curState];
        }
        for (int i=1; i<=maxChoosableInteger; ++i) {
            if ((curState & (1 << i)) == 0) {
                if (desiredTotal <= i || !dfs(maxChoosableInteger, desiredTotal - i, myMap, curState | (1 << i))) {
                    myMap[curState] = true;
                    return true;
                }
            }
        }
        myMap[curState] = false;
        return false;
    }
};
// Time : O(2^N)
// Space : O(2^N)