// 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指 **数组里任一元素出现频数的最大值** 。
//
// 你的任务是找到与 nums 拥有相同大小的度的 **最短连续子数组**，返回其长度。
//
// 示例 1: 
//
//输入: [1, 2, 2, 3, 1]
//输出: 2
//解释: 
//输入数组的度是2，因为元素1和2的出现频数最大，均为2.
//连续子数组里面拥有相同度的有如下所示:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//最短连续子数组[2, 2]的长度为2，所以返回2.
// 
//
// 示例 2: 
//
// 
//输入: [1,2,2,3,1,4,2]
//输出: 6
// 
//
// 注意: 
//
// 
// nums.length 在1到50,000区间范围内。 
// nums[i] 是一个在0到49,999范围内的整数。 
// 
// Related Topics 数组 
// 👍 186 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 理解题意：
    // 1. 先要找到数组的度对应的所有数字
    // 2. 找到这些数字中哪个数字分布最紧凑

    // 思路：
    // 1. 先利用 hash_map 存储每个数字出现的range，和次数 Time:O(N) Space:O(3 * N)，计算数组的度，以及满足数组度对应的数字
    // 3. 遍历这些数字找到最小range的数字 Time: O(M)
    // Complexity:
    // Time: O(N)
    // Space: O(3 * N)
    int findShortestSubArray(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int ans = INT_MAX;
        unordered_map<int, vector<int> > mp;
        int maxDegree = 0;
        vector<int> maxDegreeVec;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 入 mp
            if (!mp.count(nums[i]))
            {
                mp[nums[i]] = {i, 0, 1};
            } else
            {
                mp[nums[i]][1] = i;
                mp[nums[i]][2]++;
            }
            // 动态更新数组的度，及等于数组的度对应的数字
            if (mp[nums[i]][2] >= maxDegree)
            {
                if (mp[nums[i]][2] == maxDegree)
                {
                    maxDegreeVec.push_back(nums[i]);
                } else {
                    maxDegreeVec = {nums[i]};
                }
                maxDegree = mp[nums[i]][2];
            }
        }
        if (maxDegree == 1) return 1;
        for (int i = 0; i < maxDegreeVec.size(); ++i)
        {
            int dis = mp[maxDegreeVec[i]][1] - mp[maxDegreeVec[i]][0] + 1;
            if (dis < ans) ans = dis;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
