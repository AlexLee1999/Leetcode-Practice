class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = square(n);
        while (true) {
            slow = square(slow);
            fast = square(square(fast));
            if (slow == 1) {
                return true;
            }
            if (slow == fast) {
                break;
            }
        }
        return false;
    }
    int square(int n) {
        int rem;
        int result = 0;
        while (n > 0) {
            rem = n % 10;
            result += (rem * rem);
            n /= 10;
        }
        return result;
    }
};