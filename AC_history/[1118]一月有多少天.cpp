//指定年份 Y 和月份 M，请你帮忙计算出该月一共有多少天。 
//
// 
//
// 示例 1： 
//
// 输入：Y = 1992, M = 7
//输出：31
// 
//
// 示例 2： 
//
// 输入：Y = 2000, M = 2
//输出：29
// 
//
// 示例 3： 
//
// 输入：Y = 1900, M = 2
//输出：28
// 
//
// 
//
// 提示： 
//
// 
// 1583 <= Y <= 2100 
// 1 <= M <= 12 
// 
// 👍 7 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 这道题最大的考点是，闰年的定义：闰年是指能被400整除或能被4整除但是不能被100整除的年份，剩下的都是平年
    // 四年一闰,百年不闰,四百年再闰
    // 哦，无用的知识有增加了
    int numberOfDays(int Y, int M)
    {
        if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
        {
            return 31;
        } else if (M == 2)
        {
            if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0)) return 29;
            else return 28;
        } else
        {
            return 30;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
