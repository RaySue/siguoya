//有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，
//你能对此优化吗? 
//
// 示例： 
//
// 输入：words = ["I","am","a","student","from","a","university","in","a","city"], 
//word1 = "a", word2 = "student"
//输出：1 
//
// 提示： 
//
// 
// words.length <= 100000 
// 
// Related Topics  字符串
// 👍 12 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路简单，但是坑比较多
    // 1. 如果words中不包含任何一个单词，那么就返回words.size()
    // 2. 要考虑words1、words2的出现顺序问题，而且多次出现的问题
    //
    // 指针p从头向后遍历，如果遇到word1了，那么就是把word1位置存储到p1
    // 判断此时p2是否出现过，如果出现则计算距离，保存最小，没有出现继续遍历，遇到word2一样的处理

    int findClosest(vector <string> &words, string word1, string word2)
    {
        int ans = words.size();
        int p1 = -1, p2 = -1, p = 0;
        while (p < words.size())
        {
            if (words[p] == word1)
            {
                p1 = p;
                if (p2 != -1) ans = min(ans, p1 - p2);
            } else if (words[p] == word2)
            {
                p2 = p;
                if (p1 != -1) ans = min(ans, p2 - p1);
            }
            p++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
