package 剑指_Offer_06__从尾到头打印链表

type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {

	var result []int

	if head == nil {
		return nil
	}

	for head != nil {
		result = append(result, head.Val)
		head = head.Next
	}

	for i, j := 0, len(result)-1; i < j; {
		result[i], result[j] = result[j], result[i]
		i++
		j--
	}

	return result

}
