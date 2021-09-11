//给定一幅黑白像素组成的图像, 计算黑色孤独像素的数量。 
//
// 图像由一个由‘B’和‘W’组成二维字符数组表示, ‘B’和‘W’分别代表黑色像素和白色像素。 
//
// 黑色孤独像素指的是在同一行和同一列不存在其他黑色像素的黑色像素。 
//
// 示例: 
//
// 输入: 
//[['W', 'W', 'B'],
// ['W', 'B', 'W'],
// ['B', 'W', 'W']]
//
//输出: 3
//解析: 全部三个'B'都是黑色孤独像素。
// 
//
// 
//
// 注意: 
//
// 
// 输入二维数组行和列的范围是 [1,500]。 
// 
//
// 
// Related Topics 深度优先搜索 数组 
// 👍 13 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 方法三：
    // 思路
    //

    int ans = 0;
    // 利用 dfs 检测每一列数
    void dfs(vector <vector<char>> &picture, int i, int j, int &count)
    {
        if (i >= picture.size() && count == 1)
        {
            ans++;
            return;
        }
        if (i >= picture.size()) return;

        if (picture[i][j] == 'B') count++;
        dfs(picture, i + 1, j, count);
    }
    int findLonelyPixel(vector <vector<char>> &picture)
    {
        int row = picture.size();
        int col = picture[0].size();
        int count = 0;
        int column;
        for (int i = 0; i < row; ++i)
        {
            // 检测每一行
            for (int j = 0; j < col; ++j)
            {
                if (picture[i][j] == 'B')
                {
                    count++;
                    column = j;
                }
                if (count > 1) break;
            }
            if (count == 1)
            {
                // 检测列
                count = 0;
                dfs(picture, 0, column, count);
            }
            count = 0;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
