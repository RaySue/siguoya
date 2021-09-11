//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值
// 至多为 k。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3
//输出: true 
//
// nums = [1,2,3,4,2], k = 3
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,2,3,1,2,3], k = 2
//输出: false 
// Related Topics 数组 哈希表 
// 👍 195 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 标准滑窗法
    // 用散列表来维护这个k大小的滑动窗口
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if (nums.empty()) return false;
        int l = 0, r = 0, valid = 0;
        unordered_map<int, int> window;

        while(r < nums.size())
        {
            int a = nums[r];
            r++;
            if (window.count(a))
            {
                if (window[a] > 0) return true;
            }
            window[a] ++;
            valid++;
            while (valid >= k + 1)
            {
                int b = nums[l];
                l++;
                window[b] --;
                valid --;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
