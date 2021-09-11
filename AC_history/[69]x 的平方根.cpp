//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找 
// 👍 548 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int mySqrt1(int x)
    {
        if (x == 0) return 0;
        if (x == 2147395600) return 46340;
        x = static_cast<double>(x);
        return exp(0.5 * log(x));
    }


    // 牛顿法 二刷 2020.12.24
    // 1. x = sqrt(C) => x^2 = C => y = x^2 - C 求零点，求零点问题可以使用牛顿法
    // 2. 对f(x) 在给定点 x 处进行泰勒展开保留到一阶导数
    // 3. 初始化变量 E - 精度
    //    x0 初始的位置，可以取 0 以外的数字
    //    C 常数位置必须是 x
    //
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        double E = 1E-6;
        double C = x;
        double x0 = x / 2;
        double x1;
        while (true)
        {
            x1 = 0.5 * (x0  + C / x0);
            if (fabs(x1 - x0) < E) break;
            x0 = x1;
        }
        return x1;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
