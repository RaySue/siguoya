// 给定一个包含 n + 1 个整数的数组 nums，
// 其数字都在 1 到 n 之间（包括 1 和 n），
// 可知至少存在一个重复的整数。假设只有一个重复的整数，找出
// 这个重复的数。
//
// 示例 1: 
//       [-1,-3,-4,]
// 输入: [1,3,4,2,2]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [3,1,3,4,2]
//输出: 3
// 
//
// 说明： 
//
// 
// 不能更改原数组（假设数组是只读的）。 
// 只能使用额外的 O(1) 的空间。 
// 时间复杂度小于 O(n2) 。 
// 数组中只有一个重复的数字，但它可能不止重复出现一次。 
// 
// Related Topics 数组 双指针 二分查找 
// 👍 959 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷，2021.01.25
    // 方法一：利用 bucket
    // 注意 nums[i] 是下标
    int findDuplicate1(vector<int> &nums)
    {
        vector<int> bucket(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (bucket[nums[i]] == 1) return nums[i];
            bucket[nums[i]]++;
        }
        return -1;
    }

    // 自研的原地索引， 特别牛逼
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[abs(nums[i]) - 1] < 0) return abs(nums[i]);
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return -1;
    }

    // 方法二: 快慢指针
    // 相当于寻找入环口，快慢指针在哪里相遇是未知的
    int findDuplicate3(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
            {
                fast = 0;
                fast = nums[fast];
                slow = nums[slow];
                if (fast == slow) return slow;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
