//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串 
// 👍 1812 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：使用栈
    // O(N) O(N)
    bool isValid1(string s)
    {
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        stack<char> checker;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                checker.push(s[i]);
            } else
            {
                if (checker.empty() || checker.top() != mp[s[i]]) return false;
                checker.pop();
            }
        }
        return checker.empty();
    }

    // 方法二：优化空间复杂度,不可行，必须需要辅助栈，这种情况搞不定 [(])
    bool isValid(string s)
    {
        int checker1 = 0;
        int checker2 = 0;
        int checker3 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                checker1++;
            } else if (s[i] == '[')
            {
                checker2++;
            } else if (s[i] == '{')
            {
                checker3++;
            } else if (s[i] == ')')
            {
                if (checker1 <= 0) return false;
                checker1--;
            } else if (s[i] == ']')
            {
                if (checker2 <= 0) return false;
                checker2--;
            } else if (s[i] == '}')
            {
                if (checker3 <= 0) return false;
                checker3--;
            }
        }
        return checker1 + checker2 + checker3 == 0;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
