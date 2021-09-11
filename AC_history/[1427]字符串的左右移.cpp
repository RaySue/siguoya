//给定一个包含小写英文字母的字符串 s 以及一个矩阵 shift，其中 shift[i] = [direction, amount]： 
//
// 
// direction 可以为 0 （表示左移）或 1 （表示右移）。 
// amount 表示 s 左右移的位数。 
// 左移 1 位表示移除 s 的第一个字符，并将该字符插入到 s 的结尾。 
// 类似地，右移 1 位表示移除 s 的最后一个字符，并将该字符插入到 s 的开头。 
// 
//
// 对这个字符串进行所有操作后，返回最终结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc", shift = [[0,1],[1,2]]
//输出："cab"
//解释：
//[0,1] 表示左移 1 位。 "abc" -> "bca"
//[1,2] 表示右移 2 位。 "bca" -> "cab" 
//
// 示例 2： 
//
// 
//输入：s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
//输出："efgabcd"
//解释： 
//[1,1] 表示右移 1 位。 "abcdefg" -> "gabcdef"
//[1,1] 表示右移 1 位。 "gabcdef" -> "fgabcde"
//[0,2] 表示左移 2 位。 "fgabcde" -> "abcdefg"
//[1,3] 表示右移 3 位。 "abcdefg" -> "efgabcd" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 100 
// s 只包含小写英文字母 
// 1 <= shift.length <= 100 
// shift[i].length == 2 
// 0 <= shift[i][0] <= 1 
// 0 <= shift[i][1] <= 100 
// 
// Related Topics 数组 数学 
// 👍 6 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 可以使用双端队列


    // 先累计计算shift，在移动
    string stringShift(string s, vector <vector<int>> &shift)
    {
        if (s.empty()) return s;
        string ans = "";
        int shiftDirect = 0;
        for (vector<int> oneShift : shift)
        {
            if (oneShift[0] == 0)
            {
                shiftDirect -= oneShift[1];
            } else
            {
                shiftDirect += oneShift[1];
            }
        }
        if (shiftDirect == 0) return s;
        // 右移动
        if (shiftDirect > 0)
        {
            shiftDirect %= s.size();
            for (int i = s.size() - shiftDirect; i < s.size(); ++i)
            {
                ans.push_back(s[i]);
            }
            for (int i = 0; i < s.size() - shiftDirect; ++i)
            {
                ans.push_back(s[i]);
            }
        } else
        {  // 左移动
            shiftDirect = -shiftDirect;
            shiftDirect %= s.size();
            for (int i = shiftDirect; i < s.size(); ++i)
            {
                ans.push_back(s[i]);
            }
            for (int i = 0; i < shiftDirect; ++i)
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }

    // 把 s 弄成三份， 方便移动， 截取子串即可
    string stringShift(string s, vector <vector<int>> &shift)
    {
        int shiftindex = 0;
        for (int i = 0; i < shift.size(); ++i)
        {
            if (shift[i][0] == 0)
            {
                shiftindex -= shift[i][1];
            } else
            {
                shiftindex += shift[i][1];
            }
        }
        if (shiftindex >= 0)
        {
            shiftindex %= shift.size();
        } else
        {
            shiftindex = -(-shiftindex % shift.size());
        }
        string tmp = s + s + s;
        string ans = tmp.substr(s.size() - shiftindex, s.size());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
