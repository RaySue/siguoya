//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法 
// 👍 412 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 1. 暴力法 是利用 set 对结果进行去重复
    // 2. 利用前后关系进行筛选

    vector <vector<int>> ans;

    void backtrack(vector<int> nums, int depth, vector<bool> isVis, vector<int> path)
    {
        if (depth == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (isVis[i]) continue;
            // i 进入下一轮之后，如果当前元素和前一个元素相等，但是前一个元素却没有出现（isVis == False） 那么就说明越俎代庖了


            // 下面这句话的目的是相同的两个数字 1 1 如果后面的先出现，那么就不符合条件，保证相同的数字的顺序即去重复
            // 1. 前面的先出现，那么 nums[i-1] != nums[i] 继续执行
            // 2. 后面的先出现，那么 nums[i-1] == nums[i] 且 !isVis[i - 1] continue
//            if (i > 0 && nums[i-1] == nums[i] && !isVis[i - 1]) continue;
            if (i > 0 && nums[i-1] == nums[i] && !isVis[i - 1]) continue;
            path.push_back(nums[i]);
            isVis[i] = true;
            backtrack(nums, depth + 1, isVis, path);
            isVis[i] = false;
            path.pop_back();
        }

    }

    vector <vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> isVis(nums.size(), false);
        vector<int> path;
        backtrack(nums, 0, isVis, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
