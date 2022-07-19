func longestCommonSubsequence(text1 string, text2 string) int {
    s1 := len(text1)
    s2 := len(text2)
    table := make([][]int, s1 + 1)
    for i:=0; i<=s1; i++ {
        table[i] = make([]int, s2 + 1)
    }
    for i:=0; i<=len(text1); i++ {
        for j:=0; j<=len(text2); j++ {
            table[i][j] = 0
        }
    }
    maxLen := 0
    for i:=0; i<len(text1); i++ {
        for j:=0; j<len(text2); j++ {
            if text1[i] == text2[j] {
                table[i + 1][j + 1] = max(table[i + 1][j + 1], table[i][j] + 1)
            } else {
                table[i + 1][j + 1] = max(table[i + 1][j], table[i][j + 1])
            }
            maxLen = max(maxLen, table[i + 1][j + 1])
        }
    }
    return maxLen
}
func max(i int, j int) int {
    if i < j {
        return j
    }
    return i
}
// Time : O(n^2)
// Space : O(n^2)