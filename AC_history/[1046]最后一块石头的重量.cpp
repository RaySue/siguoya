// 有一堆石头，每块石头的重量都是正整数。
//
// 每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下： 
//
// 
// 如果 x == y，那么两块石头都会被完全粉碎； 
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。 
// 
//
// 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。 
//
// 
//
// 示例： 
//
// 输入：[2,7,4,1,8,1]
//输出：1
//解释：
//先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
//再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
//接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
//最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。 
//
// 
//
// 提示： 
//
// 
// 1 <= stones.length <= 30 
// 1 <= stones[i] <= 1000 
// 
// Related Topics 堆 贪心算法 
// 👍 111 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2020.12.30 每日一题
    // 题目理解：
    // 1. 每次选出最重的两块石头 x, y (x <= y)
    // 2. 粉碎规则：
    // 3. if x == y  两个元素都去掉
    // 4. if x != y  较小的石头去掉 较大的石头 y = y - x
    // 5. 计算最后剩下的石头的重量
    // 思路一：
    // 按照题意仿真即可，先给出 base 方法 使用优先队列
    // 1. 将stones 放入优先队列
    // 2. 将两个较大的出队列，运算后，如果有剩余入队列
    // 3. 当 队列 size == 1的时候返回
    int lastStoneWeight1(vector<int> &stones)
    {
        if (stones.empty()) return 0;
        if (stones.size() == 1) return stones.back();
        priority_queue<int, vector<int>, less<int> > q;  // 大顶堆
        for (int stone:stones) q.push(stone);
        while (q.size() > 1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x == y) continue;
            else
            {
                q.push(y - x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
