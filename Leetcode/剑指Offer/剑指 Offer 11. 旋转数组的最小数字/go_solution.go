package 剑指_Offer_11__旋转数组的最小数字

func minArray(numbers []int) int {
	i := 1
	if len(numbers) == 0 || len(numbers) == 1 {
		return len(numbers)
	}
	for ; i < len(numbers); i++ {
		if numbers[i] < numbers[i-1] {
			if numbers[i] < numbers[0] {
				return numbers[i]
			}
			return numbers[0]
		}
	}

	return numbers[0]
}

func minArray2(numbers []int) int {
	if len(numbers) == 0 || len(numbers) == 1 {
		return numbers[0]
	}

	high := len(numbers) - 1
	low := 0

	for low < high {
		pivot := low + (high-low)/2
		if numbers[pivot] < numbers[high] {
			high = pivot
		} else if numbers[pivot] > numbers[high] {
			low = pivot + 1
		} else {
			high--
		}

	}

	return numbers[low]

}
