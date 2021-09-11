//
// 给定一个经过编码的字符串，返回它解码后的字符串。
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。 
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。 
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 
//
// 
//
// 示例 1： 
//
// 输入：s = "3[a]2[bc]"
//输出："aaabcbc"
// 
//
// 示例 2： 
//
// 输入：s = "3[a2[c]]"
//输出："accaccacc"
// 
//
// 示例 3： 
//
// 输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
// 
//
// 示例 4： 
//
// 输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
// 
// Related Topics 栈 深度优先搜索 
// 👍 572 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：
    // 思路：
    // 深度优先搜索：我们可以认为一对 [] 的递归深度是 1， [[]] 递归深度是 2， 以此类推
    // 如整条字符串都不包含 [] 那么就依次填入到 ans 中
    // 如果遇到数字，就对数字进行 加法模型 累加
    // 如果遇到 [ 那么就找对应的 ]， 这中间可能还有 [] 所以这里进行递归 "3[[xxx]]" 先decode 为 "[xxx][xxx][xxx]"
    // 然后在使用 "[xxx][xxx][xxx]" 递归调用 decodeString
    // 核心思路流程： "3[2[a]2[xx]]" -> "3[aaxxxx]" ->  "aaxxxxaaxxxxaaxxxx"

    string ans = "";

    string decoder(int repeated, string s)
    {
        string res = "";
        s = s.substr(1, s.size() - 2);
        for (int i = 0; i < repeated; ++i)
        {
            res += s;
        }
        return res;
    }

    string decodeString1(string s)
    {
        int ptr = 0;
        int repeated = 0;
        while (ptr < s.size())
        {
            if (s[ptr] <= '9' && s[ptr] >= '0')
            {
                repeated = repeated * 10 + s[ptr] - '0';
            } else if (s[ptr] == '[')
            {
                int start = ptr;
                int count = 0;
                while (true)
                {
                    ptr++;
                    if (s[ptr] == '[') count--;
                    if (s[ptr] == ']') count++;
                    if (count == 1) break;
                }
                string sub_str = s.substr(start, ptr - start + 1);
                decodeString(decoder(repeated, sub_str));
                repeated = 0;
            } else
            {
                ans += s[ptr];
            }
            ptr++;
        }
        return ans;
    }

    // 二刷 2021.01.19
    // 方法二：
    //
    // 利用双栈，一个栈记录数字，一个栈记录数字后的字符串
    // 1. 遇到字符就添加到 res 中
    // 2. 遇到数字就开始 加法模型
    // 3. 遇到 [ 就把 num 入栈 res 入栈，num = 0, res=空
    // 4. 左括号过后一定是字符串 还是执行 1， 2， 3， 4，直到遇到右括号
    // 5. 遇到右括号就把 res 合并到栈顶元素 times 次，把结果给 res 出栈，出栈...
    // 栈和递归 是一样的，先入栈（递归入函数），再出栈（返回）
    // 通过 case 想思路：
    // avcd2[e]
    // 2[a3[bc]]



    // 以例子理解来驱动思路
    // "abc3[a]"
    // "3[a]2[bc]"
    // "3[a2[c]]"
    string decodeString(string s)
    {
        stack<int> numSta;
        stack<string> strSta;
        string ret = "";
        int num = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[')
            {
                numSta.push(num);
                num = 0;
                strSta.push(ret);
                ret = "";
            } else if (s[i] == ']')
            {
                // "abc3[cd]xyz"
                int repeatedNum = numSta.top();
                numSta.pop();
                for (int i = 0; i < repeatedNum; ++i)
                {
                    strSta.top() += ret;
                }
                ret = strSta.top();
                strSta.pop();
            } else {
                ret += s[i];
            }
        }
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
