package 剑指_Offer_10__II__青蛙跳台阶问题

func numWays(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	const mod int = 1e9 + 7
	a := 1
	b := 1
	r := 0
	for n > 1 {
		r = (a + b) % mod
		a = b
		b = r
		n--
	}

	return r
}
