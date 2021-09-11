//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [
// [1,3,5,7],
// [10,11,16,20],
// [23,30,34,50]],
// target = 3
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：matrix = [], target = 0
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 0 <= m, n <= 100 
// -104 <= matrix[i][j], target <= 104 
// 
// Related Topics 数组 二分查找 
// 👍 275 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 三刷 2020.12.23
    // 1. 暴力遍历 O(M * N)
    // 2. 行列二分法，O(log(N)+log(M) + log(N -1) + log(M - 1) + ... + 0) =  O(log(N! * M!))
    // 3. 启发式算法 O(M + N)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        int i = row;
        int j = 0;
        while(i >= 0 && j <= col)
        {
            if (matrix[i][j] < target) j++;
            else if (matrix[i][j] > target) i--;
            else return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
