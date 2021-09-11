//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表 
// 👍 9652 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.22
    // 两数之和需要返回的是下标，输入空的时候 返回空
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(target - nums[i])) return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }

    // two sum 如果使用排序的话，也只能对其下标进行排序，对原数组排序就会出问题，因为要返回下标
    // 这里利用 C++ 的lambda 表达式对下标进行排序
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> idx(nums.size());
        for (int i = 0; i < nums.size(); ++i) idx[i] = i;
        auto lambda = [=](int i1, int i2)->bool{ return nums[i1] < nums[i2];};
        sort(idx.begin(), idx.end(),lambda);
        int l = 0, r = idx.size() - 1;
        while(l < r)
        {
            int cur = nums[idx[l]] + nums[idx[r]];
            if (cur > target) r--;
            else if (cur < target) l++;
            else return {idx[l], idx[r]};
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
