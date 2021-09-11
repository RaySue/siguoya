// 三步问题。
// 有个小孩正在上楼梯，楼梯有n阶台阶，
// 小孩一次可以上1阶、2阶或3阶。
// 实现一种方法，计算小孩有多少种上楼梯的方式。
// 结果可能很大，你需要对结果模1000000007。
//
// 示例1: 
//
// 
// 输入：n = 3 
// 输出：4
// 说明: 有四种走法
// 
//
// 示例2: 
//
// 
// 输入：n = 5
// 输出：13
// 
//
// 提示: 
//
// 
// n范围在[1, 1000000]之间 
// 
// Related Topics 动态规划 
// 👍 35 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 对 1e9 + 7 取余数是因为
    // 该数内的任意两个数之和 不会溢出 INT
    // 小于该数的任意两数之积 不会溢出 long long
    int e = 1e9 + 7;

    // f(n) = f(n-1) + f(n-2) + f(n-3)
    int waysToStep(int n)
    {
        if (n < 3) return n;
        if (n == 3) return 4;
        int first = 1;
        int second = 2;
        int third = 4;
        int four = 7;
        for (int i = 4; i <= n; ++i)
        {
            four = (third + second) % e + first;
            first = second % e;
            second = third % e;
            third = four % e;
        }
        return four % e;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
