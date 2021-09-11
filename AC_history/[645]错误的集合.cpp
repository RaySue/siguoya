// 集合 S 包含从 1 到 n 的整数。
// 不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
//
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到（重复出现的整数，再找到丢失的整数），将它们以数组的形式返回。
//
// 示例 1: 
//
// 
//输入: nums = [1,2,2,4]
//输出: [2,3]
// 
//
// 注意: 
//
// 
// 给定数组的长度范围是 [2, 10000]。 
// 给定的数组是无序的。 
// 
// Related Topics 哈希表 数学 
// 👍 131 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:



    // 方法一：
    // 利用前 n 项和求和公式: n * ((a1 + an) / 2)
    // 先利用 hash_map 找到重复的数字，并对剩下的数字求和
    // 然后利用求和公式减去之前的求和，得到真实的数字
    vector<int> findErrorNums(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2) return {};
        unordered_map<int, int> mp;
        int repeatNum;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (mp.count(nums[i])) repeatNum = nums[i];
            else mp[nums[i]] ++;
        }
        int realNum = nums.size() * ((1 + nums.size())  * 1.0 / 2) - sum + repeatNum;
        return {repeatNum, realNum};
    }

    // 方法二：
    // 把所有的数字放入到 hash_map中
    // 从1到n遍历，找到没在hash_map的数和在hash_map中出现两次的数

};
//leetcode submit region end(Prohibit modification and deletion)
