//在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为
// x、纵坐标为 y 的点。 
//
// 请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
//输出：true
// 
//
// 示例 2： 
//
// 
//
// 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 2 <= coordinates.length <= 1000 
// coordinates[i].length == 2 
// -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4 
// coordinates 中不含重复的点 
// 
// Related Topics 几何 数组 数学 
// 👍 77 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 两种思路：
    // 第一种：求斜率
    // 求所有点到第一个点的斜率，如果出现斜率不同，那么返回 false
    // 使用斜率要注意垂直的情况，即分母为 0 的情况

    // 第二种：利用共线向量的行列式值为 0 这一性质
    // 每个点和第一个点计算得到向量
    // 每两个向量计算 是否共线
    bool checkStraightLine(vector <vector<int>> &coordinates)
    {
        int n = coordinates.size();
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x = coordinates[1][0] - x0;
        int y = coordinates[1][1] - y0;
        for (int i = 2; i < n; ++i)
        {
            int xi = coordinates[i][0] - x0;
            int yi = coordinates[i][1] - y0;
            // 计算二阶行列式
            // 构造每个点到第一个点的向量 向量 ab = b - a 相应坐标相减
            // 两个向量 （x1, y1） (x2, y2), 如果两个向量共线，那么组成的行列式值为 0，所以不为 0 说明不共线，返回 false
            if (x * yi - y * xi)
            {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
