package 剑指_Offer_03__数组中重复的数字

func FindRepeatNumber(nums []int) int {
	NumsMap := make(map[int]int)

	for i, j := range nums {
		if _, ok := NumsMap[j]; ok {
			return j
		}

		NumsMap[j] = i
	}

	return -1

}
