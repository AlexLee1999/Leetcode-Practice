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
        queue<NestedInteger> myQueue;
        int depth = 1;
        int sum = 0;
        vector<int> arr;
        vector<int> depth_arr;
        for (int i=0; i<nestedList.size(); ++i) {
            myQueue.push(nestedList[i]);
        }
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for (int j = 0; j<size; ++j) {
                NestedInteger nested = myQueue.front();
                myQueue.pop();
                if (nested.isInteger()) {
                    arr.push_back(nested.getInteger());
                    depth_arr.push_back(depth);
                } else {
                    for (int i=0; i<nested.getList().size(); ++i) {
                        myQueue.push(nested.getList()[i]);
                    }
                }
            }
            depth ++;
        }
        for (int i=0; i<depth_arr.size(); ++i) {
            depth_arr[i] = depth - depth_arr[i];
            sum += depth_arr[i] * arr[i];
        }
        return sum;
    }
};