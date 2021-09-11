//给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。 
//
// 完成所有替换操作后，请你返回这个数组。 
//
// 
//
// 示例： 
//
// 
//输入：arr = [17,18,5,4,6,1]
//输出：      [18,6,6,6,1,-1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^4 
// 1 <= arr[i] <= 10^5 
// 
// Related Topics 数组 
// 👍 54 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 一刷 2021.01.01
    // 先回忆了一下单调栈，发现想复杂了
    // 发现和接雨水的问题的一小部分很像，倒序遍历，保存最大值即可
    vector<int> replaceElements(vector<int>& arr)
    {
        if (arr.empty()) return {};
        int nextMax;
        int curMax = arr.back();
        arr.back() = -1;
        for (int i = arr.size() - 2; i >= 0; --i)
        {
            nextMax = max(curMax, arr[i]);
            arr[i] = curMax;
            curMax = nextMax;
        }
        return arr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
