//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。 
//
// 
//
// 示例 1： 
//
// 输入：
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出：
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
// 
//
// 示例 2： 
//
// 输入：
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出：
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//]
// 
// Related Topics 数组 
// 👍 19 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 一刷 2020.12.19
    // 利用 unordered_map 存储 0 的位置，然后迭代器遍历置零，如果M、N小于32的话可以用整数来存储（位移运算）
    // O(M * N)
    // O(max(M, N))
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> zeroRow;
        unordered_set<int> zeroCol;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRow.insert(i);
                    zeroCol.insert(j);
                }
            }
        }
        unordered_set<int>::iterator iterRow = zeroRow.begin();
        unordered_set<int>::iterator iterCol = zeroCol.begin();
        for(;iterRow != zeroRow.end(); ++iterRow)
        {
            for(int i = 0; i < matrix[0].size(); ++i)
            {
                matrix[*iterRow][i] = 0;
            }
        }
        for(;iterCol != zeroCol.end(); ++iterCol)
        {
            for(int i = 0; i < matrix.size(); ++i)
            {
                matrix[i][*iterCol] = 0;
            }
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
