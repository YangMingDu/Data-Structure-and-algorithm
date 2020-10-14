优化最大索引堆：

利用反向查找，reverse数组，reverse[i]表示的是i这个索引在数组中的位置。

indexes[i] = j;
reverse[j] = i;

indexes[reverse[i]] = i;
reverse[indexes[i]] = i;