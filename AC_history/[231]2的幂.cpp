//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。 
//
// 示例 1: 
//
// 输入: 1
//输出: true
//解释: 20 = 1 
//
// 示例 2: 
//
// 输入: 16
//输出: true
//解释: 24 = 16 
//
// 示例 3: 
//
// 输入: 218
//输出: false 
// Related Topics 位运算 数学 
// 👍 238 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 方法一： 位运算
    // 2的幂的值域 （0， inf）
    bool isPowerOfTwo(int n)
    {
        return n > 0 && !(n & n - 1);
    }

    // 方法二 计算 log2 n 然后判断是否为整数
    bool isPowerOfTwo2(int n)
    {
        if (n <= 0) return false;
        if (n == 1) return true;
        double a = n;
        double res = log2(a);
        n = static_cast<int> (res);
        return res == n;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
