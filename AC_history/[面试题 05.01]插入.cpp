// 插入。给定两个32位的整数N与M，以及表示比特位置的i 与 j。编写一种方法，
// 将M插入N，使得M从N的第j位开始，到第i位结束。假定从j位到i位足以容纳M，也即
// 若M = 10011，那么j和i之间至少可容纳5个位。
// 例如，不可能出现j = 3 和 i = 2的情况，因为第3位和第2位之间放不下M。
//
// 示例1: 
//
//  输入：N = 1024(10000000000), M = 19(10011), i = 2, j = 6
//  输出：N = 1100(10001001100)
//
//        1000 01010 00
//             10011
//        0000 00000 11
//        0000 11111 11
//        0000 11111 00
//        1111 00000 11
//        1000 00000 00
// 示例2:
//
//  输入： N = 0, M = 31(11111), i = 0, j = 4
// 输出：N = 31(11111)
// 
// Related Topics 位运算 
// 👍 21 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路一样，为什么我写的代码像一坨屎，而且还通过不了
    // 2020.12.30, 如果你的所有代码都写的是最工整，最漂亮的，那你还刷题干嘛？
    int insertBits(int N, int M, int i, int j)
    {
        int low = 1;
        while (i > 0)
        {
            low = (low << 1);
            M = (M << 1);
            i--;
        }
        low -= 1;

        int high = 1;
        if (j == 31)
        {
            high = INT_MAX;
        } else
        {
            while (j >= 0)
            {
                high = (high << 1);
                j--;
            }
            high -= 1;
        }
        high -= low;
        high = ~high;
        N &= high;
        return M + N;
    }


    // 一刷 2020.12.30
    // 思路可以简单，也可以复杂
    // start
    // 先将 N 对应的i 到 j 铲掉 置0
    // 然后将M 左移i位 加到 N
    // end
    int insertBits(int N, int M, int i, int j)
    {
        for (int k = i; k <= j; k++)
        {
            if (N & (1 << k))
            {
                N -= (1 << k);
            }
        }
        N += (M << i);
        return N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
