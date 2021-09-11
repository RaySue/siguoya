//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针 
// 👍 2833 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 此题不是求下标，所以可以排序，排序后双指针解决
    // 1. 异常判断
    // 2. for 去重复
    // 3. while 去重复
    // 二刷依然不熟练 2020.12.22
    // 利用自定义的 QS 来代替 sort 函数
    // [-1, -1, 0, 1, 2, -1, -4]
    vector <vector<int>> threeSum(vector<int> &nums)
    {
        vector <vector<int>> ans;
//        sort(nums.begin(), nums.end());
        quickSort(nums);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int cur = nums[l] + nums[r];
                if (cur < -nums[i])
                {
                    l++;
                } else if (cur > -nums[i])
                {
                    r--;
                } else
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l - 1] == nums[l]) l++;
                    while (l < r && nums[r + 1] == nums[r]) r--;
                }
            }
        }
        return ans;
    }

private:

    // 两种版本的快速排序
    void quickSort(vector<int> &nums)
    {
//        quickSort(nums, 0, nums.size() - 1);  // QS 递归版本
        quickSortIter(nums, 0, nums.size() - 1);  // QS 迭代版本
    }
    void quickSortIter(vector<int> &nums, int low, int high)
    {
        if (low >= high) return;
        stack <vector<int>> sta;
        sta.push({low, high});
        while (!sta.empty()) {
            vector<int> loc = sta.top();
            sta.pop();
            int pi = partition(nums, loc[0], loc[1]);
            if (loc[0] < pi - 1) sta.push({loc[0], pi - 1});
            if (pi + 1 < loc[1]) sta.push({pi + 1, loc[1]});
        }
    }
    void quickSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
    int partition(vector<int> &nums, int i, int j)
    {
        int begin = i;
        int pivot = nums[begin];
        while (i != j)
        {
            while (i < j && nums[j] >= pivot) j--;
            while (i < j && nums[i] <= pivot) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[begin], nums[i]);
        return i;
    }
};








//leetcode submit region end(Prohibit modification and deletion)
