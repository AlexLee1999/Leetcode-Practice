func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] + nums[j] == target {
                if i != j{
				    return []int{i, j}
                }
			}
		}
	}
    return []int{0, 0}
}