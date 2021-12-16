package 剑指_Offer_10__I__斐波那契数列

func fib(n int) int {

	a := 0
	b := 1
	r := 0
	const mod int = 1e9 + 7

	if n <= 1 {
		return n
	}

	for n > 1 {
		r = (a + b) % mod
		a = b
		b = r
		n--
	}

	return r

}
