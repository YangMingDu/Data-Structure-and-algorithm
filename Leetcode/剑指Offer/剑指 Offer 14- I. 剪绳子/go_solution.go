package 剑指_Offer_14__I__剪绳子

func CuteRobe(n int) int {
	if n < 2 {
		return 0
	} else if n == 2 {
		return 1
	} else if n == 3 {
		return 2
	}
	var max int
	var f []int = make([]int, n+1)
	f[1] = 1
	f[2] = 2
	f[3] = 3
	for i := 4; i <= n; i++ {
		max = 0
		for j := 1; j <= i/2; j++ {
			tmpRopeM := f[j] * f[i-j]
			if max < tmpRopeM {
				max = tmpRopeM
			}
			f[i] = max
		}

	}
	return f[n]

}
