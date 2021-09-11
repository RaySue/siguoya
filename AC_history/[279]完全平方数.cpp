//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
//
// 示例 1: 
//
// 输入: n = 12
//输出: 3 
//解释: 12 = 4 + 4 + 4. 
//
// 示例 2: 
//
// 输入: n = 13
//输出: 2
//解释: 13 = 4 + 9. 
// Related Topics 广度优先搜索 数学 动态规划 
// 👍 735 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 完全平方数 - 四平方定理
    // 每个正整数均可表为四个整数的平方和(其中有些整数可以为零)
    // 利用 hash set 从 1 开始对每个数字进行平方 存入 hash set，判断其中是否有 n 有 返回 1
    // 然后把 hash set 中的数字两两做和得到 hash set2，判断其中是否有 n 有 返回 2
    // 在把 hash set2 和 hash set 1中合并，判断其中是否有 n 有 返回 3
    // 返回 4
    int numSquares(int n)
    {
        int num = 1;
        unordered_set<int> set1;
        for(;;)
        {
            if (num * num > n) break;
            set1.insert(num * num);
            num++;
        }
        if (set1.count(n)) return 1;

        unordered_set<int> set2;
        for (int i : set1)
        {
            for (int j : set1)
            {
                set2.insert(i + j);
            }
        }
        if (set2.count(n)) return 2;

        for (int i : set1)
        {
            if (set2.count(n - i)) return 3;
        }
        return 4;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
