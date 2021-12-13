package 剑指_Offer_04__二维数组中的查找

func findNumberIn2DArray(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}

	row := len(matrix[0])

	for i, j := 0, len(matrix[0])-1; i < row && j >= 0; {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] > target {
			j--
		} else {
			i++
		}
	}
	return false

}
