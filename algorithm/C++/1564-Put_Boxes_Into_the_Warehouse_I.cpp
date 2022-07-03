class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater<int>());
        int box_ptr = 0;
        int count = 0;
        for (int i=0; i<warehouse.size(); ++i) {
            while (box_ptr < boxes.size() && boxes[box_ptr] > warehouse[i]) {
                box_ptr ++;
            }
            if (box_ptr == boxes.size()) {
                return count;
            }
            box_ptr ++;
            count ++;
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(1)