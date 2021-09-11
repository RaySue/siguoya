// 给定一个矩阵 A， 返回 A 的转置矩阵。
//
// 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。 
//
// 
//
// 示例 1： 
//
// 输入：[[1,2,3],
//       [4,5,6],
//       [7,8,9]]

//输出：[[1,4,7],
//      [2,5,8],
//      [3,6,9]]

//
//
// 示例 2： 
//
// 输入：[[1,2,3],
//       [4,5,6]]

//输出：[[1,4],
//      [2,5],
//      [3,6]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 1000 
// 1 <= A[0].length <= 1000 
// 
// Related Topics 数组 
// 👍 122 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 转置的定义，行变列，列变行
    // 1. 根据A的行列生成一个列行的向量
    // 2. 然后把A[j][i]填入到ans[i][j]中
    // Complexity:
    // Time: O(N*M)
    // Space: O(1) 输出不计入
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> ans(col, vector<int>(row, 0));
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                ans[i][j] = A[j][i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
