//求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。 
//
// 
//
// 示例 1： 
//
// 输入: n = 3
//输出: 6
// 
//
// 示例 2： 
//
// 输入: n = 9
//输出: 45
// 
//
// 
//
// 限制： 
//
// 
// 1 <= n <= 10000 
// 
// 👍 236 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2021.01.06
    // 注意：不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
    //1. 如果某个判断语句里面是 a & b，那么计算机会先判断 a 是否为 true，然后不管 a 是否为 true，
    //计算机都会接着去运行 b 语句，然后判断 b 是否为 true。最后 a & b 的结果则是由 a 的结果和 b 的结果做一个 “与” 运算得到。
    //2. 但是如果某个判断语句里面是 a && b，那么计算机会先判断 a 是否为 true，
    //假如 a 为 true，那么计算机会接着运行 b 语句，如果 b 为 true 那 a && b 为 true，否则为 false；
    //但是如果 a 为 false，那计算机会直接返回 a && b = false，而不会再去运行 b 语句了。
    //3. 我们正是利用这个特性，规避了使用条件判断语句来判断是否为递归出口。
    int sumNums(int n)
    {
        n && (n += sumNums(n - 1));
        return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
