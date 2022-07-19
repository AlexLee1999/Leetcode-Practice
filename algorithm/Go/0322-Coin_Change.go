func coinChange(coins []int, amount int) int {
    table := make([]int, amount + 1)
    for i:=0; i<=amount; i++ {
        table[i] = math.MaxInt
    }
    table[0] = 0
    for i:=0; i<=amount; i++ {
        for j:=0; j<len(coins); j++ {
            if i >= coins[j] {
                if table[i - coins[j]] != math.MaxInt {
                    if table[i] > table[i - coins[j]] + 1 {
                        table[i] = table[i - coins[j]] + 1
                    }
                }
            }
        }
    }
    if table[amount] == math.MaxInt {
        return -1
    }
    return table[amount]
}
// Time : O(nk)
// Space : O(n)