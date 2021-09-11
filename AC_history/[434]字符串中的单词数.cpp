//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。 
//
// 请注意，你可以假定字符串里不包括任何不可打印的字符。 
//
// 示例: 
//
// 输入: "Hello, my name is John"
//输出: 5
//解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
// 
// Related Topics 字符串 
// 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 使用内置函数： split 函数 (不管哪种语言) 返回长度为 {O}(n) 的数组/列表，故算法使用线性的额外空间。

    // 一次遍历
    // time O(n)
    // space O(1)
    // 如果字符为空，那么就继续循环，如果不为空，那么要看下是否是单词结束导致的
    int countSegments(string s)
    {
        int count = 0;
        if (s.empty()) return count;
        bool end = false;
//        s.push_back(' ');  // 让最后一个单词能够被计数，没想到这个操作导致排名比较靠后
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ') end = true;
            if (end && s[i] == ' ')
            {
                end = false;
                count ++;
            }
        }
        // 如果用这个操作一定要注意为空的情况，否则下标越界
        if (s.back() != ' ') count ++;
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
