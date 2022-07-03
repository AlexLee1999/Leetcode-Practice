class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] > b[1]; 
        });
        int num_box = 0;
        int total_weight = 0;
        for (int i=0; i<boxTypes.size(); ++i) {
            if (num_box + boxTypes[i][0] > truckSize) {
                total_weight += ((truckSize - num_box) * boxTypes[i][1]);
                return total_weight;
            }
            num_box += boxTypes[i][0];
            total_weight += (boxTypes[i][0] * boxTypes[i][1]);
        }
        return total_weight;
    }
};
// Time : O(nlogn)