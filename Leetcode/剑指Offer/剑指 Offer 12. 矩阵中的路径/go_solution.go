package 剑指_Offer_12__矩阵中的路径

//回溯
func exist(board [][]byte, word string) bool {
	m := len(board)
	n := len(board[0])
	//所有起点
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			res := dfs(board, word, i, j, 0)
			if res == true {
				return true
			}
		}
	}

	return false

}

func dfs(a [][]byte, word string, x int, y int, k int) bool {
	m := len(a)
	n := len(a[0])
	//所有word都遍历出来了
	if k >= len(word) {
		return true
	}
	//走错路的情况或者达到边境
	if x >= m || y >= n || x < 0 || y < 0 || a[x][y] != word[k] {
		return false
	}
	//不会再往回头走，a->b，之后b不能再到a
	tmp := a[x][y]
	a[x][y] = '.'

	//向其余三个方向走
	res := dfs(a, word, x+1, y, k+1) || dfs(a, word, x-1, y, k+1) || dfs(a, word, x, y+1, k+1) || dfs(a, word, x, y-1, k+1)

	//会到之前的节点之后，第二步之后的节点恢复原状
	a[x][y] = tmp

	if res == true {
		return true
	}

	return false

}
