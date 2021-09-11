//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 3
//输出: [1,3,3,1]
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？ 
// Related Topics 数组 
// 👍 175 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> helper(int n)
    {
        if (n == 1) return {1,1};
        if (n == 2) return {1,2,1};
        vector<int> back = helper(n - 1);
        vector<int> tmp(back.size() + 1, 1);  // 初始化 n 个 1
        for (int i = 1; i < back.size(); ++i)
        {
            tmp[i] = back[i - 1] + back[i];
        }
        return tmp;
    }

    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0) return {1};
        return helper(rowIndex);
    }


};
//leetcode submit region end(Prohibit modification and deletion)
