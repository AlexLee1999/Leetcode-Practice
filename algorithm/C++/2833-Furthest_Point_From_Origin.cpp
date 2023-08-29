class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0;
        int l = 0;
        for (int i=0; i<moves.size(); ++i) {
            if (moves[i] == 'R') {
                r ++;
            } else if (moves[i] == 'L') {
                l ++;
            }
        }
        int move = abs(r - l);
        return move + moves.size() - (r + l);
    }
};