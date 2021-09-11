// 数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。
//
// 示例 1： 
//
// 输入：[1,2,5,9,5,9,5,5,5]
//输出：5 
//
// 
//
// 示例 2： 
//
// 输入：[3,2]
//输出：-1 
//
// 
//
// 示例 3： 
//
// 输入：[2,2,1,1,1,2,2]
//输出：2 
//
// 
//
// 说明： 
//你有办法在时间复杂度为 O(N)，空间复杂度为 O(1) 内完成吗？ 
// Related Topics 位运算 数组 分治算法 
// 👍 55 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 摩尔投票法 二刷 2020.12.29，之前对摩尔投票只是粗略的了解一个大概，LC里面重复的题多是好事情，而且重复的题，一般都是面试的重点
    //
    // 群雄割据，大乱斗
    // 思路：
    // 先初始第一个元素是 cur
    // 开始战斗
    // 如果遇到不是 cur 的那么 life --
    // 如果遇到cur遇到和自身一样的 life ++
    // 当 life < 0 的时候 cur 死亡， cur = nums[i] 复活，life = 0，避免（3，1，1，3）的情况，要对life置零
    // 最终剩下的大概率是 大于一半元素的
    // 如果本就不存在这样的元素，我们需要再遍历一遍筛选一下，**根据题意**
    int majorityElement(vector<int> &nums)
    {
        if (nums.empty()) return -1;
        int cur = nums[0];
        int life = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (cur == nums[i]) life++;
            else life--;
            if (life < 0)  // [1,2,1] 为了避免1，2，1的情况下错杀，所以即使life为0，也先不能宣告死亡
            {
                cur = nums[i];
                life = 0;
            }
        }
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == cur) count++;
        }
        return count > nums.size() / 2? cur: -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
