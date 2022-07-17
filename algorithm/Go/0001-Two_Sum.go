func twoSum(nums []int, target int) []int {
    myMap := map[int]int{}
    for i := 0; i < len(nums); i++ {
        if j, ok := myMap[target - nums[i]]; ok {
            return []int {j, i}
        }
        myMap[nums[i]] = i;
	}
    return []int{0, 0}
}
// Time : O(n)
// Space : O(n)