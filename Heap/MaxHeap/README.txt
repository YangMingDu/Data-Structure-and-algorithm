
实现一个最大堆;

 堆的构成：

私有部分：存入的数据data
	  堆的容量 capacity
	  堆中元素的数量 count
	  shiftUp操作（用于添加数据）
	  shiftDown操作（用于删除数据）

公有部分：构造函数（用于创造一个堆的空间）
	  析构函数（用于删除借用的空间）
	  判断堆是否为空（bool isEmpty）
                    输出堆元素的个数（count）
                    向堆添加元素（insert）
	  从堆删除元素（extraitMax，从根节点删除）
	  