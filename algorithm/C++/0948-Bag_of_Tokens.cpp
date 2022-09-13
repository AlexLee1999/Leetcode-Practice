class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if (tokens.empty()) {
            return 0;
        }
        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int max_score = 0;
        while (left <= right && (tokens[left] <= power || score >= 1)) {
            while (left <= right && tokens[left] <= power) {
                power -= tokens[left];
                left ++;
                score ++;
                max_score = max(max_score, score);
            }
            if (left <= right && score >= 1) {
                power += tokens[right];
                score --;
                right --;
            }
        }
        return max_score;
    }
};
// Time : O(nlogn)
// Space : O(1)