// 给你一个 **排序后的字符列表 letters **，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。
//
// 在比较时，字母是依序循环出现的。举个例子： 
//
// 
// 如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a' 
// 
//
// 
//
// 示例： 
//
// 输入:
//letters = ["c", "f", "j"]
//target = "a"
//输出: "c"
//
//输入:
//letters = ["c", "f", "j"]
//target = "c"
//输出: "f"
//
//输入:
//letters = ["c", "f", "j"]
//target = "d"
//输出: "f"
//
//输入:
//letters = ["c", "f", "j"]
//target = "g"
//输出: "j"
//
//输入:
//letters = ["c", "f", "j"]
//target = "j"
//输出: "c"
//
//输入:
//letters = ["c", "f", "j"]
//target = "k"
//输出: "c"
// 
//
// 
//
// 提示： 
//
// 
// letters长度范围在[2, 10000]区间内。 
// letters 仅由小写字母组成，最少包含两个不同的字母。 
// 目标字母target 是一个小写字母。 
// 
// Related Topics 二分查找 
// 👍 107 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.12
    // 看似简单的二分法，暗藏玄机，题目中没说有重复字母，那么你就需要提前沟通清楚
    // 题目是二分法的一种变体，要找到大于 target 的最小值，也就是紧挨着 target 的右边的第一个不同的字母
    // 二分法的过程很简单，就是简单的找 target 的二分法，但是要注意以下几种情况：
    // 1. target 不在 letters 中
    // 2. 左边界 l 溢出，只能是右溢出，因为 l 是不断向右走的，如果 target 比全数组都大，那么就返回 letters 的第一个元素
    // 3. 右边界 r 溢出，只能是左溢出，因为 r 是不断向左走的，如果 target 比全数组都小，那么也返回 letters 的第一个元素
    // 注意 重复字符的情况，重复的字符可能恰好等于 target
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (letters.empty()) return ' ';
        int l = 0, r = letters.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (letters[mid] == target)
            {
                for (int i = mid + 1; i < letters.size(); ++i)
                {
                    if (letters[i] != letters[i - 1]) return letters[i];
                }
                return letters[0];
            } else if (letters[mid] < target)
            {
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }
        return (r < 0 || l >= letters.size())? letters[0]: letters[r + 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
