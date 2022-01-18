/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i=0; i<n; ++i) {
            // if candidate knows i, candidate is not celebrity
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        // check that celebrity is valid
        for (int i=0; i<n; ++i) {
            if (i == candidate) {
                continue;
            }
            if (!knows(i, candidate) || knows(candidate, i)) {
                return -1;
            }
        }
        return candidate;
    }
};