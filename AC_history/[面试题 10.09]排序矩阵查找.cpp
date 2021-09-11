//给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// [
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
// Related Topics 双指针 二分查找 分治算法 
// 👍 17 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 1. 直接遍历：O(N^2)
    // 2. 二分法
    //    遍历对角线元素，每个对角线元素和下方二分查找，和右方二分查找
    //    log(N) + log(M) + log(N-1) + log (M - 1) + ... + 0
    //    log(N * (N - 1) * ... * 1) + log (M * (M - 1) * ... * 1)
    //    O(log(N!*M!))
    // 3. O(min(M, N)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i = matrix.size() - 1;
        int j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] < target)
            {
                j++;
            } else if (matrix[i][j] > target)
            {
                i--;
            } else {
                return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
