// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。 
//
// 注意: 
//假设字符串的长度不会超过 1010。 
//
// 示例 1: 
//
// 
//输入:
//"abccccdd"
//
//输出:
//7
//
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
// 
// Related Topics 哈希表 
// 👍 231 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 思路：
    // 1. 将字符串都加入到 hash_map 中，统计每个字符出现的个数
    // 2. 如果出现偶数个，那么直接加入到maxLen中
    // 3. 如果出现奇数个，那么就把 长度-1 加入到maxLen中，因为偶数才能对称
    // 4. 最后加个奇数点即可
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (char ss:s) mp[ss]++;
        unordered_map<char, int>::iterator iter;
        int maxLen = 0;
        bool containOdd = false;
        for (iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second % 2 == 0)
            {
                maxLen += iter->second;  //如果是偶数，那么就直接相加
            } else
            {
                maxLen += iter->second - 1; //如果是奇数，那么就取其偶数加进来
                containOdd = true;
            }
        }
        return containOdd ? maxLen + 1 : maxLen;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
