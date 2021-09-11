//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
// 感谢 Marcos 贡献此图。
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针 
// 👍 1583 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 三刷：2020.12.23
    // 这是我刷Lc的前几道题之一
    // 思路很简单，但是我依然不能飞快的写出来，这就说明LC就得多练习，别无他法
    // 无他，但手熟尔
    int trap(vector<int>& height)
    {
        if (height.empty()) return 0;
        int volume = 0;
        int leftMax = height[0];
        vector<int> leftHeight(height.size());
        int rightMax = height.back();
        vector<int> rightHeight(height.size());
        for (int i = 0; i < height.size(); ++i)
        {
            leftMax = max(leftMax, height[i]);
            leftHeight[i] = leftMax;
            rightMax = max(rightMax, height[height.size() - i - 1]);
            rightHeight[height.size() - i - 1] = rightMax;
        }
        for (int i = height.size() - 1; i >= 0; --i)
        {
            volume += min(leftHeight[i], rightHeight[i]) - height[i];
        }
        return volume;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
