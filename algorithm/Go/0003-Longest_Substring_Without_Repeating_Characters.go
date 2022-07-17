func lengthOfLongestSubstring(s string) int {
    left := 0
    myMap := map[byte]int{}
    maxLen := 0
    for right := 0; right < len(s); right++ {
        myMap[s[right]] ++;
        for myMap[s[right]] >= 2 {
            myMap[s[left]] --
            left ++
        }
        if maxLen < right - left + 1 {
            maxLen = right - left + 1
        }
    }
    return maxLen
}
// Time : O(n)
// Space : O(n)