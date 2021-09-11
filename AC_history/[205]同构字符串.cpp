// 给定两个字符串 s 和 t，判断它们是否是同构的。
//
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。 
//
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。*两个字符不能映射到同一个字符上*，但字符可以映射自己本身。
//
// 示例 1: 
//
// 输入: s = "egg", t = "add"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "foo", t = "bar"
//输出: false 
//
// 示例 3: 
//
// 输入: s = "paper", t = "title"
//输出: true 
//
// 说明: 
//你可以假设 s 和 t 具有相同的长度。 
// Related Topics 哈希表 
// 👍 233 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.27
    // 1. 记录从 s[i] 到 t[i] 的替换记录
    // 2. 如果 mp[s[i]] != t[i] return false；
    // 3. 利用 unordered_set<char> 来记录 t[i] 是否被映射过，如果被映射过，那么新元素不能再映射 t[i] 返回 false。 (题目要求：*两个字符不能映射到同一个字符上*)
    // 4. 遍历结束返回 true
    bool isIsomorphic(string s, string t)
    {
        if (s.empty()) return true;
        unordered_map<char, char> mp;
        unordered_set<char> isVis;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!mp.count(s[i]))
            {
                if (isVis.count(t[i])) return false;
                mp[s[i]] = t[i];
                isVis.insert(t[i]);
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }














};
//leetcode submit region end(Prohibit modification and deletion)
