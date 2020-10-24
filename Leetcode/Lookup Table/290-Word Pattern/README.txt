给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：利用双map映射，将单词对应字符，字符对应单词，只需要查看两个map与单词是否一致就可以了。

易错点：一定要双重认证，即正着检查一遍，再反着检查一遍，即正着检查一遍，再反着检查一遍，因为如果出现str或者parttern只有一种字符时，出现双重赋值，只会取最后一次赋值，会判定失误。