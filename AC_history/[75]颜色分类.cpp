//
// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
//
// 注意: 
//不能使用代码库中的排序函数来解决这道题。 
//
// 示例: 
//
// 输入: [2,0,2,1,1,0]
//输出: [0,0,1,1,2,2] 
//
// [0,0,1,1,2,2]
//
// 进阶： 
//
// 
// 一个直观的解决方案是使用计数排序的两趟扫描算法。 
// 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。 
// 你能想出一个仅使用常数空间的一趟扫描算法吗？ 
// 
// Related Topics 排序 数组 双指针 
// 👍 578 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一 排序，O(nlogn)

    // 方法二 遍历两次nums O(n + n) -> O(n)
    // 第一次，把所有的 0 放在前面，类似零移动
    // 第二次，把所有的 2 放在后面，类似零移动
    void sortColors1(vector<int> &nums)
    {
        int ptr = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[ptr++], nums[i]);
            }
        }

        ptr = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] == 2)
            {
                swap(nums[ptr--], nums[i]);
            }
        }
    }

    // 方法三 基于双指针的一次遍历
    // 把 0 放在前面，把 2 放在后面
    void sortColors2(vector<int> &nums)
    {
        int l = 0, p = 0, r = nums.size() - 1;
        while (p <= r)
        {
            if (nums[p] == 0)  // 遇到 0 交换，p++ l++
            {
                swap(nums[p++], nums[l++]);
            } else if (nums[p] == 2)  // 遇到 2 交换， r--， 此时p不加1，因为p的位置可能是0
            {
                swap(nums[p], nums[r--]);
            } else  // 遇到 1, p++
            {
                p++;
            }
        }
    }


    void sortColors(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int p = 0;
        while (p <= r)
        {
            if (nums[p] == 0)
            {
                swap(nums[l++], nums[p++]); // l++, p++
            } else if (nums[p] == 2)
            {
                swap(nums[r--], nums[p]);
            } else
            {
                p++;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
