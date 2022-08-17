class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int, int>> myQueue_knows;
        int mod = 1e9 + 7;
        myQueue_knows.push({1, 1});
        queue<pair<int, int>> myQueue_shares;
        int share_num = 0;
        for (int i=2; i<=n; ++i) {
            while (!myQueue_knows.empty() && myQueue_knows.front().first <= i - delay) {
                myQueue_shares.push(myQueue_knows.front());
                share_num = (share_num + myQueue_knows.front().second) % mod;
                myQueue_knows.pop();
            }
            while (!myQueue_shares.empty() && myQueue_shares.front().first + forget <= i) {
                share_num = (share_num - myQueue_shares.front().second + mod) % mod;
                myQueue_shares.pop();
            }
            if (!myQueue_shares.empty()) {
                myQueue_knows.push({i, share_num});
            }
        }
        long long count = 0;
        while (!myQueue_knows.empty()) {
            count = (count + myQueue_knows.front().second) % mod;
            myQueue_knows.pop();
        }
        while (!myQueue_shares.empty()) {
            count = (count + myQueue_shares.front().second) % mod;
            myQueue_shares.pop();
        }
        return count % mod;
    }
};
// Time : O(n)
// Space : O(n)