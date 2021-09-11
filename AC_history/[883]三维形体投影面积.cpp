//在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。 
//
// 每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。 
//
// 现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。 
//
// 投影就像影子，将三维形体映射到一个二维平面上。 
//
// 在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。 
//
// 返回所有三个投影的总面积。 
//
// 
//
// 
// 
//
// 
// 
//
// 
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：[[2]]
//输出：5
// 
//
// 示例 2： 
//
// 输入：[[1,2],[3,4]]
//输出：17
//解释：
//这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
//
// 
//
// 示例 3： 
//
// 输入：[[1,0],[0,2]]
//输出：8
// 
//
// 示例 4： 
//
// 输入：[[1,1,1],[1,0,1],[1,1,1]]
//输出：14
// 
//
// 示例 5： 
//
// 输入：[[2,2,2],[2,1,2],[2,2,2]]
//输出：21
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length = grid[0].length <= 50 
// 0 <= grid[i][j] <= 50 
// 
// Related Topics 数学 
// 👍 46 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2020.01.02 三视图
    // 很简单的一道题，但是做起来没那么容易，刷题到现在，我发现一个问题，很多题可能都包含一个通用的小模型
    // 这个题目对应的小模型就是 如何一次遍历拿到 每列的最大值，和每行的最大值，是不是和判断 **有效的数独是一样的**
    // 思路：
    // 题目是要求取三个视角投影的面积。
    // 1. 我们是按行遍历的，所以每轮迭代 都可以轻松获得每行的最大值，那么每列的最大值一定是最后一轮迭代结束之后才能得到的，
    // 所以我们用额外的数组 colMaxVec 来存储
    // 2. 对最终的 colMaxVec 再reduce sum
    // 3. 注意如果 grid[i][j]为 0，要对俯视图的面积 -1
    int projectionArea(vector <vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty()) return 0;
        int xy = grid.size() * grid.size();
        int xz = 0;
        int yz = 0;
        vector<int > colMaxVec(grid.size());
        for (int i = 0; i < grid.size(); ++i)
        {
            int rowMax = grid[i][0];
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0) xy --;
                rowMax = max(rowMax, grid[i][j]);
                colMaxVec[j] = max(grid[i][j], colMaxVec[j]);
            }
            xz += rowMax;
        }
        for (int a:colMaxVec)
        {
            yz += a;
        }
        return xy + xz + yz;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
