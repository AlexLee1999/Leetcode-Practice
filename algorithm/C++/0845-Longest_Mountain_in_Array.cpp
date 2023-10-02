lass Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool up = false;
        bool down = false;
        int count = 0;
        int max_length = 0;
        for (int i=0; i<arr.size() - 1; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff == 0) {
                count = 0;
                up = false;
                down = false;
            } else if (diff > 0 && !down) {
                count ++;
                up = true;
            } else if (diff > 0 && down) {
                down = false;
                count = 1;
                up = true;
            } else if (diff < 0 && !down) {
                down = true;
                count ++;
            } else {
                count ++;
            }
            if (up && down) {
                max_length = max(max_length, count);
            }
        }
        if (max_length == 0) {
            return 0;
        }
        return max_length + 1;
    }
};