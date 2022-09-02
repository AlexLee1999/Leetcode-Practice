class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> myQueue;
        unordered_set<string> visited;
        myQueue.push({0, 1});
        myQueue.push({0, -1});
        visited.insert("0_1");
        visited.insert("0_-1");
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                if (front.first == target) {
                    return step;
                }
                int next_pos_ad = front.first + front.second;
                int next_speed_ad = front.second * 2;
                int next_pos_rev = front.first;
                int next_speed_rev = front.second > 0 ? -1: 1;
                string advance = to_string(next_pos_ad) + "_" + to_string(next_speed_ad);
                string reverse = to_string(front.first) + "_" + to_string(next_speed_rev);
                if (!visited.count(advance) && next_pos_ad > 0 && next_pos_ad < 2 * target) {// prune the imposible search
                    visited.insert(advance);
                    myQueue.push({next_pos_ad, next_speed_ad});
                }
                if (!visited.count(reverse)) {
                    visited.insert(reverse);
                    myQueue.push({next_pos_rev, next_speed_rev});
                }
            }
            step ++;
        }
        return 0;
    }
};
// Time : O(T)
// Space : O(T)