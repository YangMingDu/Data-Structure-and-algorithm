package 剑指_Offer_05_替换空格

func replaceSpace(s string) string {

	resultStr := ""

	for _, i := range s {
		if i == ' ' {
			resultStr += "%20"
			continue
		}
		//Go 中遍历string 类型是rune， 需要转成 string
		resultStr += string(i)
	}

	return resultStr
}

func replaceSpaceSolution2(s string) string {

	origin := []byte(s)
	var count int
	for _, i := range s {
		if i == ' ' {
			count++
		}
	}

	tmp := make([]byte, count*2)
	origin = append(origin, tmp...)

	i := len(s) - 1
	j := len(origin) - 1

	for i >= 0 {
		if s[i] == ' ' {
			origin[j] = '0'
			origin[j-1] = '2'
			origin[j-2] = '%'
			i--
			j -= 3
			continue
		}

		origin[j] = s[i]
		j--
		i--
	}

	return string(origin)

}
