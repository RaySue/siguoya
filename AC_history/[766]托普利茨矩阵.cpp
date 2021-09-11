//给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。 
//
// 如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [
// [1,2,3,4],
// [5,1,2,3],
// [9,5,1,2]
// ]
//输出：true
//解释：
//在上述矩阵中, 其对角线为: 
//"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。 
//各条对角线上的所有元素均相同, 因此答案是 True 。
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2],[2,2]]
//输出：false
//解释：
//对角线 "[1, 2]" 上的元素不同。 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 20 
// 0 <= matrix[i][j] <= 99 
// 
//
// 
//
// 进阶： 
//
// 
// 如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？ 
// 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？ 
// 
// Related Topics 数组 
// 👍 181 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 1. 先遍历行的每个元素，判断其对应的对角线上的所有元素是否相同
    // 2. 在遍历列的每个元素，判断其对应的对角线上的所有元素是否相同
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (!isSameEye(matrix, i, 0)) return false;
        }
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (!isSameEye(matrix, 0, j)) return false;
        }
        return true;
    }

private:

    bool isSameEye(vector<vector<int>>& matrix, int i, int j)
    {
        int pivot = matrix[i][j];
        while (i + 1 < matrix.size() && j + 1 < matrix[0].size())
        {
            if (matrix[i + 1][j + 1] != pivot) return false;
            i++;
            j++;
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
