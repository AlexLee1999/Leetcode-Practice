class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1;
        int max_defense = 0;
        for (int i=0; i<damage.size(); ++i) {
            ans += damage[i];
            max_defense = max(max_defense, damage[i]);
        }
        return ans - min(armor, max_defense);
    }
};
// Time : O(n)
// Space : O(n)