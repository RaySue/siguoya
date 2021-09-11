//给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。 
//
// 示例 1: 
//
// 输入: 16
//输出: true
// 
//
// 示例 2: 
//
// 输入: 5
//输出: false 
//
// 进阶： 
//你能不使用循环或者递归来完成本题吗？ 
// Related Topics 位运算 
// 👍 145 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 方法一：利用取模运算，进行遍历，如果最终的结果为1，那么就是4的幂。


    // 方法二： 数学，1/2 log2(n)，及如果log2（n）的结果是整数且是偶数，那么就是4的幂
    bool isPowerOfFour(int num)
    {
        if (num <= 0) return false;
        double a = num;
        a = log2(a);
        int b = static_cast<int>(a);
        return a == b && !(b & 1);
    }

    // 方法三： 位运算，先判断是2的幂，如果是2的幂且与3取模为1，那么就是4的幂
};
//leetcode submit region end(Prohibit modification and deletion)
