package main

import "fmt"

func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] + nums[j] == target {
				    return []int{i, j}
			}
		}
	}
    return []int{0, 0}
}

func main() {
    lst := []int{2, 3, 4}
    fmt.Println(twoSum(lst, 6))
}
