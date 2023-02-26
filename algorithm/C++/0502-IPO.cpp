class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> arr;
        for (int i=0; i<profits.size(); ++i) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, less<int>> myHeap;
        int cur = w;
        int i = 0;
        for (int j=0; j<k; ++j) {
            while (i < profits.size() && arr[i].first <= cur) {
                myHeap.push(arr[i].second);
                i ++;
            }
            if (myHeap.empty()) {
                break;
            }
            cur += myHeap.top();
            myHeap.pop();
        }
        return cur;
    }
};