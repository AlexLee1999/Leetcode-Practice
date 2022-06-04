class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxLen(answerKey, k, 'T'), maxLen(answerKey, k, 'F'));
    }
    int maxLen(string answerKey, int k, char ch) {
        int len = 0;
        int right = 0;
        int left = 0;
        int char_num = 0;
        for (right = 0; right < answerKey.size(); ++right) {
            if (answerKey[right] != ch) {
                char_num ++;
            }
            while (char_num > k) {
                if (answerKey[left] != ch) {
                    char_num --;
                }
                left ++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};