func longestPalindrome(s string) string {
    maxLen := 0
    start := 0
    for i:=0; i<len(s); i++ {
        if i != len(s) - 1 {
            findPalindrome(s, i, i + 1, &maxLen, &start)
        }
        findPalindrome(s, i, i, &maxLen, &start)
    }
    return s[start:start + maxLen]
}
func findPalindrome(s string, left int, right int, maxLen *int, start *int) {
    for left >= 0 && right < len(s) {
        if s[left] == s[right] {
            if *maxLen < right - left + 1 {
                *maxLen = right - left + 1
                *start = left
            }
        } else {
            return
        }
        left --;
        right ++;
    }
}
// Time : O(n^2)
// Space : O(1)