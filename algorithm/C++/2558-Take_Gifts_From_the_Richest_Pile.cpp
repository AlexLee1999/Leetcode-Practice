class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>, less<int>> myHeap;
        for (int i=0; i<gifts.size(); ++i) {
            myHeap.push(gifts[i]);
        }
        for (int i=0; i<k; ++i) {
            int top = myHeap.top();
            myHeap.pop();
            int tmp = sqrt(top);
            myHeap.push(tmp);
        }
        long long ans = 0;
        while (!myHeap.empty()) {
            ans += myHeap.top();
            myHeap.pop();
        }
        return ans;
    }
};
// Time : O(klogn + n)
// Space : O(n)