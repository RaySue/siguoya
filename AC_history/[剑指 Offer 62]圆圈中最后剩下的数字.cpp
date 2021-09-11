// 0,1,,n-1 这 n 个数字排成一个圆圈，
// 从数字0开始，每次从这个圆圈里删除第 m 个数字。
// 求出这个圆圈里剩下的最后一个数字。
//
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。 
//
//
// 示例 1： 
//
// 输入: n = 5, m = 3
//输出: 3
// 
//
// 示例 2： 
//
// 输入: n = 10, m = 17
//输出: 2
// 
//
// 
//
// 限制： 
//
// 
// 1 <= n <= 10^5 
// 1 <= m <= 10^6 
// 
// 👍 269 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 1. 每删除一次，长度就会减少 1
    // 2. 每次从删除节点的下一个开始 作为第一个
    // 0 1 2 3 4
    // 0 1 3 4
    // 1 3 4
    // 1 3
    // 3
    /**
     *
    ### 解题思路
    最终剩下一个人时的安全位置肯定为0，反推安全位置在人数为n时的编号
    人数为1： 0
    人数为2： (0 + m) % 2
    人数为3： ((0 + m) % 2 + m) % 3
    人数为4： (((0 + m) % 2 + m) % 3 + m) % 4
    ........
    迭代推理到n就可以得出答案

    **牛逼的倒推法，其实没有正向的模拟好理解，但是效率却极高**
    * 每次计算谁能留下
    * 一个人的时候不用说了 0 肯定是留下的
    * 两个人的时候 m % 2 余数就是留下的，如果恰好是 2 的倍数，那还是 0 留下
    * 三个人的时候 (上一轮的结果) % 3 也就是上一轮留下的看下这轮谁会留下
    * 以此类推，得到最终留下的 ans = （ans + m）% i，和动态规划思想一样的
    * 有 i 个人的时候谁能留下，i + 1 谁能留下取决于 i 个人的时候谁能留下
     */
    int lastRemaining(int n, int m)
    {
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            ans = (ans + m) % i;
        }
        return ans;
    }

    // C++ 利用 list 仿真方法 Time out
    // 0 1 2 3 4
    // 0 1 3 4
    // 1 3 4
    // 1 3
    // 3
    // 0 1 2
    // 1 2
    // 1
    int lastRemaining2(int n, int m)
    {
        list<int> cycle(n, 0);
        list<int>::iterator iter = cycle.begin();
        for (int i = 0; iter != cycle.end(); ++iter, ++i) *iter = i;
        int start = 0;
        iter = cycle.begin();
        while (cycle.size() > 1)
        {
            start += m - 1;
            start %= cycle.size();
            iter = cycle.begin();
            for (int i = 0; i < start; ++i) iter++;  // list 是双链表，只能遍历挪动
            cycle.erase(iter);
        }
        return *cycle.begin();
    }


};
//leetcode submit region end(Prohibit modification and deletion)
