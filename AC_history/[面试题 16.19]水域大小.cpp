// 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。
// 由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。
// 编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
// 示例： 
// 输入：
//[
//  [0,2,1,0],
//  [0,1,0,1],
//  [1,1,0,1],
//  [0,1,0,1]
//]
//输出： [1,2,4]
// 
// 提示： 
// 
// 0 < len(land) <= 1000 
// 0 < len(land[i]) <= 1000 
// 
// Related Topics 深度优先搜索 广度优先搜索 
// 👍 34 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void dfs(vector<vector<int>> &land, int i, int j, int &area)
    {
        // bound
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] != 0) return;
        if (land[i][j] == 0) area++;
        land[i][j] = 1;
        for (int p = 0; p < 8; ++p) dfs(land, i + direction[p][0], j + direction[p][1], area);
    }

    vector<int> pondSizes(vector <vector<int>> &land)
    {
        vector<int> ans;
        for (int i = 0; i < land.size(); ++i)
        {
            for (int j = 0; j < land[0].size(); ++j)
            {
                if (land[i][j] == 0)
                {
                    int area = 0;
                    dfs(land, i, j, area);
                    ans.push_back(area);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
