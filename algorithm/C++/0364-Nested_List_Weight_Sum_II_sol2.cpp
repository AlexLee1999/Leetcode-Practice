/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0;
        int ans = 0;
        findDepth(nestedList, maxDepth, 1);
        dfs(nestedList, maxDepth, 1, ans);
        return ans;
    }
    void findDepth(vector<NestedInteger>& nestedList, int& maxDepth, int depth) {
        maxDepth = max(maxDepth, depth);
        for (int i=0; i<nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                continue;
            }
            if (!nestedList[i].getList().empty()) {
                findDepth(nestedList[i].getList(), maxDepth, depth + 1);
            }
            
        }
    }
    void dfs(vector<NestedInteger>& nestedList, int maxDepth, int depth, int& ans) {
        for (int i=0; i<nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                ans += (nestedList[i].getInteger() * (maxDepth - depth + 1));
                continue;
            }
            dfs(nestedList[i].getList(), maxDepth, depth + 1, ans);
        }
    }
};
// Time : O(n)
// Space : O(D)