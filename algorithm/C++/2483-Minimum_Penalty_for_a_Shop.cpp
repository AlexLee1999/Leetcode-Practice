class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = INT_MAX;
        int min_index = 0;
        int n = customers.size();
        vector<int> customer(n + 1, 0);
        vector<int> empty(n + 1, 0);
        for (int i=0; i<n; ++i) {
            if (customers[i] == 'N') {
                empty[i + 1] = empty[i] + 1;
            } else {
                empty[i + 1] = empty[i];
            }
        }

        for (int j=n - 1; j >= 0; --j) {
            if (customers[j] == 'Y') {
                customer[j] = customer[j + 1] + 1; 
            } else {
                customer[j] = customer[j + 1]; 
            }
        }

        for (int i=0; i <= n; ++i) {
            if (penalty > (empty[i] + customer[i])) {
                penalty = empty[i] + customer[i];
                min_index = i;
            }
            
        }
        return min_index;
    }
};