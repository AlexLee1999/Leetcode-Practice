class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap;
        int n = apples.size();
        int count = 0;
        int i = 0;
        while (true) {
            if (i < n) {
                myHeap.push({i + days[i], apples[i]});
            }
            while (!myHeap.empty() && myHeap.top().first <= i) {
                myHeap.pop();
            }
            if (!myHeap.empty() && myHeap.top().first > i) {
                pair<int, int> top = myHeap.top();
                count ++;
                myHeap.pop();
                if (top.second > 1) {
                    myHeap.push({top.first, top.second - 1});
                }
            }
            if (myHeap.empty() && i >= n) {
                break;
            }
            i ++;
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(n)