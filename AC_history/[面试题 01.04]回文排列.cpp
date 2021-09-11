// 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//
// 回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。 
//
// 回文串不一定是字典当中的单词。 
//
// 
//
// 示例1： 
//
// 输入："tactcoa"
//输出：true（排列有"tacocat"、"atcocta"，等等）
// 
//
// 
// Related Topics 哈希表 字符串 
// 👍 40 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2020.12.19
    // 思路：利用unordered_map 来记录字符出现的奇数次，如果奇数次 > 1，返回false，否则就是回文串
    // 可以使用计数桶，注意要问清楚字符的范围，是否都是大小写字符
    bool canPermutePalindrome(string s)
    {
        unordered_map<char, int> record;
        for (auto c:s) record[c]++;
        unordered_map<char, int>::iterator iter = record.begin();
        int oddCount = 0;
        for (; iter != record.end(); iter++)
        {
            if (iter->second % 2 != 0) oddCount++;
            if (oddCount > 1) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
