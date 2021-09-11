// 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
//输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
//输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学 
// 👍 76 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int findNthDigit(int n)
    {
        //初始化
        int digit = 1;  //位数
        long start = 1; //每个 digit 开始的数字
        long count = 9; //在digit位数中 数位的数量 = 9*start*digit
        //1.求所在num的位数 digit
        while (n > count)
        {    //说明n所在num比之前的位数digit大
            n -= count;   //减去上一个位数的数位的总和
            digit++;
            start *= 10;
            count = 9 * start * digit;
        }
        /**
         * 目前的n是已经减去了比它小的位数的总和
         * 比如n为15的话，指向的是12数字的2，那么此时的n则为15-9=6
         */
        //2.求所在的数字num
        long num = start + (n - 1) / digit;
        //3.求所在num的第几位
        int i = (n - 1) % digit;
        return to_string(num)[i] - '0';
    }
};
//leetcode submit region end(Prohibit modification and deletion)
