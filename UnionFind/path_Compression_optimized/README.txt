路线压缩优化思路：

将所有元素都指向其根节点，利用递归，让每一个x的父亲节点都是find的结果就可以了。

但是实践显示由于递归的时间较长，并没有原路径压缩效率高。

