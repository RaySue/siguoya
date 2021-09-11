// 在一个 m*n 的棋盘的每一格都放有一个礼物，
// 每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，
// 并每次 **向右** 或者 **向下** 移动一格、直
// 到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
//
// 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,3,1],        1 4 5
//  [1,5,1],        2 9 10
//  [4,2,1]         6 11 12
//]
//输出: 12
//解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物 
//
// 
//
// 提示： 
//
// 
// 0 < grid.length <= 200 
// 0 < grid[0].length <= 200 
// 
// Related Topics 动态规划 
// 👍 89 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    //  grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
    int maxValue(vector <vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;
        for (int j = 1; j < grid[0].size(); ++j) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < grid.size(); ++i) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < grid.size(); ++i)
        {
            for (int j = 1; j < grid[0].size(); ++j)
            {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid.back().back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
