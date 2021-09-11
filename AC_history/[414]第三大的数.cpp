//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。 
//
// 示例 1: 
//
// 
//输入: [3, 2, 1]
//
//输出: 1
//
//解释: 第三大的数是 1.
// 
//
// 示例 2: 
//
// 
//输入: [1, 2]
//
//输出: 2
//
//解释: 第三大的数不存在, 所以返回最大的数 2 .
// 
//
// 示例 3: 
//
// 
//输入: [2, 2, 3, 1]
//
//输出: 1
//
//解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。
// 
// Related Topics 数组 
// 👍 164 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 高射炮打蚊子使用 priority_queue<int>;
    // 注意重复数字的时候还会有影响
    int thirdMax1(vector<int> &nums)
    {
        priority_queue<int> pq;
        unordered_set<int> numsSet;
        for (int n : nums)
        {
            numsSet.insert(n);
        }
        unordered_set<int>::iterator iter;
        for (iter = numsSet.begin(); iter != numsSet.end(); ++iter) pq.push(*iter);
        if (pq.size() < 3) return pq.top();
        for (int i = 0; i < 2; ++i)
        {
            pq.pop();
        }
        return pq.top();
    }

    // 维护三个变量 m1 m2 m3 即可
    // 避开整型的最小值，我们可以用long型的最小值来初始化即可
    int thirdMax(vector<int> &nums)
    {
        long int m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = nums[i];
            } else if (nums[i] > m2 && nums[i] < m1) // 注意数字重复的情况 保证小于 m1
            {
                m3 = m2;
                m2 = nums[i];
            } else if (nums[i] >= m3 && nums[i] < m2) // 注意数字重复的情况 保证小于 m2
            {
                m3 = nums[i];
            }
        }
        return m3 != LONG_MIN ? m3 : m1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
