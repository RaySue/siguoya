// 给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：
//
// 
// 任何左括号 ( 必须有相应的右括号 )。 
// 任何右括号 ) 必须有相应的左括号 ( 。 
// 左括号 ( 必须在对应的右括号之前 )。 
// * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。 
// 一个空字符串也被视为有效字符串。 
// 
//
// 示例 1: 
//
// 
//输入: "()"
//输出: True
// 
//
// 示例 2: 
//
// 
//输入: "(*)"
//输出: True
// 
//
// 示例 3: 
//
// 
//输入: "(*))"
//输出: True
// 
//
// 注意: 
//
// 
// 字符串大小将在 [1，100] 范围内。 
// 
// Related Topics 字符串 
// 👍 178 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    //
    // 切记如果不是做过的题，不要上来就用最优的解法解题，注意审题
    // 双栈解决带星括号问题
    //
    bool checkValidString(string s)
    {
        stack<char> left;
        stack<char> star;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') left.push(i);
            else if (s[i] == '*') star.push(i);
            else
            {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        if (left.size() > star.size()) return false;
        while (!left.empty() && !star.empty())
        {
            if (left.top() > star.top()) return false;  // *( 一旦出现这种情况，立马返回false
            left.pop();
            star.pop();
        }
        return left.empty();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
