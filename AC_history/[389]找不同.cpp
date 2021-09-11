// 给定两个字符串 s 和 t，它们只包含小写字母。
//
// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。 
//
// 请找出在 t 中被添加的字母。 
//
// 
//
// 示例: 
//
// 输入：
//s = "abcd"
//t = "abcde"
//
//输出：
//e
//
//解释：
//'e' 是那个被添加的字母。
// 
// Related Topics 位运算 哈希表 
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.18

    // 方法一： 使用hash map
    char findTheDifference1(string s, string t)
    {
        // 使用两个 hash map 是为了避免字符重复出现的情况没法判断
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (char k:s) sMap[k]++;
        for (char k:t) tMap[k]++;
        for (char k:t)
        {
            if (!sMap.count(k)) return k;
            else if (tMap[k] > sMap[k]) return k;
        }
        return ' ';
    }

    // 方法二： 计数排序思想
    // 如果元素是有限制的，比如都是小写字母，或都是数字，立马要想到利用计数思想来代替 hash map
    char findTheDifference(string s, string t)
    {
        vector<int> bucket(26, 0);
        for (char c:t)
        {
            bucket[c - 'a'] ++;
        }
        for (char c:s)
        {
            bucket[c - 'a'] --;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (bucket[i] == 1)
            {
                return i + 'a';
            }
        }
        return ' ';
    }

};
//leetcode submit region end(Prohibit modification and deletion)
