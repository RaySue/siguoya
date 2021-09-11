//给定两个字符串, A 和 B。 
//
// A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后
//，A 能变成B，那么返回True。 
//
// 
//示例 1:
//输入: A = 'abcde', B = 'cdeab'
//输出: true
//
//示例 2:
//输入: A = 'abcde', B = 'abced'
//输出: false 
//
// 注意： 
//
// 
// A 和 B 长度不超过 100。 
// 
// 👍 110 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 方法一，利用substr
    bool rotateString1(string A, string B)
    {
        if (A.size() != B.size()) return false;
        if (A.empty() && B.empty()) return true;
        int n = A.size();
        for (int i = 0; i < n; ++i)
        {
            if (A.substr(i, A.size()) == B) return true;
            A.push_back(A[i]);
        }
        return false;
    }

    // 方法二，直接使用find
    bool rotateString(string A, string B)
    {
        return A.size() != B.size() ? false : (A + A).find(B) != -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
