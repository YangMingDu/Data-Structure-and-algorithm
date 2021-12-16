package 剑指_Offer_07__重建二叉树__

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{preorder[0], nil, nil}

	i := 0

	for ; i < len(preorder); i++ {
		if inorder[i] == preorder[0] {
			break
		}
	}

	//前序遍历[根｜左子树｜右子树] 递归 也就是说左子树的根就是左子树的[0]
	//中序遍历[左子树｜根｜右子树] 递归
	//思路就是找到左子树的根结点、右子树的根结点，递归。
	root.Left = buildTree(preorder[1:len(inorder[:i])+1], inorder[:i])
	root.Right = buildTree(preorder[len(inorder[:i])+1:], inorder[i+1:])

	return root

}
