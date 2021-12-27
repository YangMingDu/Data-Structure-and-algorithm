package 剑指_Offer_13__机器人的运动范围

var MapGone [][]bool
var count int

func movingCount(m int, n int, k int) int {
	count = 0

	MapGone = make([][]bool, m)
	for k, _ := range MapGone {
		MapGone[k] = make([]bool, n)
	}

	dfs(0, 0, k, m, n)

	return count

}

func IfCanGo(x int, y int, m int, n int, k int) bool {
	tmpx, tmpy := x, y
	var result int
	for {
		result += x % 10
		x = x / 10
		if x == 0 {
			break
		}
	}

	for {
		result += y % 10
		y = y / 10
		if y == 0 {
			break
		}
	}

	if result <= k && tmpx >= 0 && tmpx < m && tmpy >= 0 && tmpy < n {
		return true
	}

	return false
}

func dfs(x int, y int, k int, m int, n int) {

	if IfCanGo(x, y, m, n, k) && MapGone[x][y] != true {
		count += 1
		MapGone[x][y] = true
	} else {
		return
	}

	dfs(x-1, y, k, m, n)
	dfs(x+1, y, k, m, n)
	dfs(x, y+1, k, m, n)
	dfs(x, y-1, k, m, n)

}
