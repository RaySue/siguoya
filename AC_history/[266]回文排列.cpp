//给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。 
//
// 示例 1： 
//
// 输入: "code"
//输出: false 
//
// 示例 2： 
//
// 输入: "aab"
//输出: true 
//
// 示例 3： 
//
// 输入: "carerac"
//输出: true 
// Related Topics 哈希表 
// 👍 23 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 利用集合，
    // 集合里存放出现了奇数次的字符。在对字符串进行遍历时，
    // 如果字符 mathrmc  在集合中，就把它删除，否则就把它添加进集合中。
    // 在遍历完整个字符串后，集合的大小就表示字符串中出现奇数次的字符的数目。

    // hash map
    bool canPermutePalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto c:s) mp[c]++;
        unordered_map<char, int>::iterator iter;
        int oddsCount = 0;
        for (iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second % 2 != 0) oddsCount++;
            if (oddsCount > 1) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
