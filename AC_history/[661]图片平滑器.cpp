// 包含整数的二维矩阵 M 表示一个图片的灰度。
// 你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，
// 如果周围的单元格不足八个，则尽可能多的利用它们。
//
// 示例 1: 
//
// 
//输入:
//[[1,1,1],
// [1,0,1],
// [1,1,1]]
//输出:
//[[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
//解释:
//对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
//对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
//对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
// 
//
// 注意: 
//
// 
// 给定矩阵中的整数范围为 [0, 255]。 
// 矩阵的长和宽的范围均为 [1, 150]。 
// 
// Related Topics 数组 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    int kernal(vector <vector<int>> &M, int i, int j)
    {
        int val = M[i][j];
        int count = 1;
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            val += M[i - 1][j - 1];
            count++;
        }
        if (i - 1 >= 0)
        {
            val += M[i - 1][j];
            count++;
        }
        if (i - 1 >= 0 && j + 1 < M[0].size())
        {
            val += M[i - 1][j + 1];
            count++;
        }
        if (j - 1 >= 0)
        {
            val += M[i][j - 1];
            count++;
        }
        if (j + 1 < M[0].size())
        {
            val += M[i][j + 1];
            count++;
        }
        if (i + 1 < M.size() && j + 1 < M[0].size())
        {
            val += M[i+1][j+1];
            count++;
        }
        if (i + 1 < M.size())
        {
            val += M[i+1][j];
            count++;
        }
        if (i + 1 < M.size() && j - 1 >= 0)
        {
            val += M[i+1][j-1];
            count++;
        }
        return val / count;
    }

    vector <vector<int>> imageSmoother(vector <vector<int>> &M)
    {
        vector <vector<int>> ans(M);
        for (int i = 0; i < M.size(); ++i)
        {
            for (int j = 0; j < M[0].size(); ++j)
            {
                ans[i][j] = kernal(M, i, j);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
