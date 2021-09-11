//你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。 
//
// 给定一个数字 n，找出可形成完整阶梯行的总行数。 
//
// n 是一个非负整数，并且在32位有符号整型的范围内。 
//
// 示例 1: 
//
// 
//n = 5
//
//硬币可排列成以下几行:
//¤
//¤ ¤
//¤ ¤
//
//因为第三行不完整，所以返回2.
// 
//
// 示例 2: 
//
// 
//n = 8
//
//硬币可排列成以下几行:
//¤
//¤ ¤
//¤ ¤ ¤
//¤ ¤
//
//因为第四行不完整，所以返回3.
// 
// Related Topics 数学 二分查找 
// 👍 80 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 方法一，暴力
    int arrangeCoins1(int n)
    {
        int count = 0;
        int row = 1;
        while(n > 0)
        {
            n -= row;
            row ++;
            count ++;
        }
        if (n < 0) count --;
        return count;
    }

    // 方法二，等差数列求和
    int arrangeCoins(int n)
    {
        // 注意，n是int型，所以 8*n也是int型，可能存在越界
        long long x = n;
        long long a = static_cast<long long>((sqrt(1 + 8 * x) - 1) / 2);
        return a;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
