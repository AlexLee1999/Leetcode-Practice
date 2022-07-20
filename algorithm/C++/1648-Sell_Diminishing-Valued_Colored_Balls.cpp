class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long left = 0;
        long right = *max_element(inventory.begin(), inventory.end());
        int mod = 1e9 + 7;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(inventory, orders, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int count_orders = 0;
        long long ans = 0;
        int price = left + 1;
        long long lower_price = left * (left + 1) / 2;
        for (int i=0; i<inventory.size(); ++i) {
            if (inventory[i] < price) continue;
            long long total_price = ((long long)inventory[i] * (1 + (long long)inventory[i]) / 2);
            ans += (total_price - lower_price) % mod;
            ans %= mod;
            count_orders += (inventory[i] - price + 1);
        }
        ans += (left * (orders - count_orders)) % mod;
        return ans % mod;
        
    }
    int isPossible(vector<int>& inventory, int orders, int value) {
        int count = 0;
        for (int i=0; i<inventory.size(); ++i) {
            count += max(inventory[i] - value, 0);
            if (count > orders) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nlogk)
// Space : O(1)