//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [
// ["1","0","1","0","0"],
// ["1","0","1","1","1"],
// ["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 动态规划 
// 👍 627 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
    // 短板原理，如果某个位置的上方，左上方，右方都是1，加上这个位置也是 1 那么这个位置就是一个小正方形
    //
    int maximalSquare(vector <vector<char>> &matrix)
    {
        if (matrix.empty()) return 0;

        int row = matrix.size() + 1;
        int col = matrix[0].size() + 1;
        vector <vector<int>> m(row, vector<int>(col, 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '0') continue;
                m[i + 1][j + 1] = min(min(m[i][j + 1], m[i + 1][j]), m[i][j]) + 1;
                ans = max(ans, m[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
