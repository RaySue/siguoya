//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。 
//
// 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。 
//
// 
//
// 示例 1： 
//
// 输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
// 
//
// 示例 2： 
//
// 输入：name = "saeed", typed = "ssaaedd"
//输出：false
//解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
// 
//
// 示例 3： 
//
// 输入：name = "leelee", typed = "lleeelee"
//输出：true
// 
//
// 示例 4： 
//
// 输入：name = "laiden", typed = "laiden"
//输出：true
//解释：长按名字中的字符并不是必要的。
// 
//
// 
//
// 提示： 
//
// 
// name.length <= 1000 
// typed.length <= 1000 
// name 和 typed 的字符都是小写字母。 
// 
//
// 
//
// 
// Related Topics 双指针 字符串 
// 👍 102 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // name = "saeed", typed = "ssaaedd"
    bool isLongPressedName(string name, string typed)
    {
        if (name == typed) return true;
        if (!name.empty() && typed.empty()) return false;
        int p1 = 0, p2 = 0;
        char mem = ' ';
        for(;;)
        {
//            cout << name[p1] << " " << typed[p2] << endl;
            if (name[p1] == typed[p2])
            {
                mem = name[p1];
                p1++;
                p2++;
            } else {
                if (typed[p2] == mem)
                {
                    p2++;
                } else {
                    return false;
                }
            }
            if (p1 >= name.size() || p2 >= typed.size()) break;
        }
        for (int i = p2; i < typed.size(); ++i) if (typed[i] != name.back()) return false;
        return p1 == name.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
