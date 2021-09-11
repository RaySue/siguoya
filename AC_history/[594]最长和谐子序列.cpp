// 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
//
// 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,2,5,2,3,7]
//输出: 5
//原因: 最长的和谐数组是：[3,2,2,2,3].
// 
//
// 说明: 输入的数组长度最大不超过20,000. 
// Related Topics 哈希表 
// 👍 131 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路:
    // 利用 hash map 把所有的数字存储一遍，并记录出现的次数 O(N) O(N)
    // 然后通过迭代器来遍历hash_map，对其 key 值加减 1 的范围进行比较取最大值 O(N) O(N)
    // Complexity:
    // Time: O(N)
    // Space: O(N)
    int findLHS(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto n:nums) mp[n]++;
        unordered_map<int, int>::iterator iter;
        for (iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (mp.count(iter->first - 1))
            {
//                if (mp[iter->first - 1] + iter->second > ans)
//                {
//                    ans = mp[iter->first - 1] + iter->second;
//                }
                ans = max(mp[iter->first - 1] + iter->second, ans);
            } else if (mp.count(iter->first + 1))
            {
//                if (mp[iter->first + 1] + iter->second > ans)
//                {
//                    ans = mp[iter->first + 1] + iter->second;
//                }
                ans = max(mp[iter->first + 1] + iter->second, ans);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
