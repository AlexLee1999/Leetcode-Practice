class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> count;
        for (int i=0; i<hand.size(); ++i) {
            count[hand[i]] ++;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            int num = it->first;
            if (it->second == 0) {
                continue;
            }
            while (it->second > 0) {
                for (int i=num; i<num + groupSize; ++i) {
                    if (count[i] == 0) {
                        return false;
                    }
                    count[i] --;
                }
            }
        }
        return true;
    }
};