//你被给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值： 
//
// 
// -1 表示墙或是障碍物 
// 0 表示一扇门 
// INF 无限表示一个空的房间。然后，我们用 231 - 1 = 2147483647 代表 INF。你可以认为通往门的距离总是小于 2147483647 
//的。 
// 
//
// 你要给每个空房间位上填上该房间到 最近 门的距离，如果无法到达门，则填 INF 即可。 
//
// 示例： 
//
// 给定二维网格： 
//
// INF  -1  0  INF
//INF INF INF  -1
//INF  -1 INF  -1
//  0  -1 INF INF
// 
//
// 运行完你的函数后，该网格应该变成： 
//
//   3  -1   0   1
//  2   2   1  -1
//  1  -1   2  -1
//  0  -1   3   4
// 
// Related Topics 广度优先搜索 
// 👍 86 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 非常笨重的解法
    // 1. 遍历得到每个门的位置 入队列
    // 2. 利用 isVis 记录已经走过的位置
    // 3. 从每个门开始广度优先搜索，然后记录最小值
    void wallsAndGates1(vector <vector<int>> &rooms)
    {
        queue <pair<int, int>> q;
        set <pair<int, int>> isVis;
        for (int i = 0; i < rooms.size(); ++i)
        {
            for (int j = 0; j < rooms[0].size(); ++j)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                    isVis.insert({i, j});
                }
            }
        }

        int step = 1;
        while (!q.empty())
        {
            int sz = q.size();
            bool flag = false;
            for (int k = 0; k < sz; ++k)
            {
                pair<int, int> loc = q.front();
                q.pop();
                int i = loc.first, j = loc.second;
                if (i - 1 >= 0 && isVis.find({i - 1, j}) == isVis.end() && rooms[i - 1][j] != -1)
                {
                    rooms[i - 1][j] = min(rooms[i - 1][j], step);
                    q.push({i - 1, j});
                    isVis.insert({i - 1, j});
                    flag = true;
                }
                if (i + 1 < rooms.size() && isVis.find({i + 1, j}) == isVis.end() && rooms[i + 1][j] != -1)
                {
                    rooms[i + 1][j] = min(rooms[i + 1][j], step);
                    q.push({i + 1, j});
                    isVis.insert({i + 1, j});
                    flag = true;
                }
                if (j - 1 >= 0 && isVis.find({i, j - 1}) == isVis.end() && rooms[i][j - 1] != -1)
                {
                    rooms[i][j - 1] = min(rooms[i][j - 1], step);
                    q.push({i, j - 1});
                    isVis.insert({i, j - 1});
                    flag = true;
                }
                if (j + 1 < rooms[0].size() && isVis.find({i, j + 1}) == isVis.end() && rooms[i][j + 1] != -1)
                {
                    rooms[i][j + 1] = min(rooms[i][j + 1], step);
                    q.push({i, j + 1});
                    isVis.insert({i, j + 1});
                    flag = true;
                }
            }
            if (!flag) break;
            step++;
        }
    }


    // 轻盈的解法
    // 1. 先找到所有的们 入队列
    void wallsAndGates(vector <vector<int>> &rooms)
    {
        queue <pair<int, int>> q;
        for (int i = 0; i < rooms.size(); ++i)
        {
            for (int j = 0; j < rooms[0].size(); ++j)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> loc = q.front();
            q.pop();
            int i = loc.first, j = loc.second;
            if (i - 1 >= 0 &&  rooms[i - 1][j] == INT_MAX )
            {
                rooms[i - 1][j] = rooms[i][j] + 1;
                q.push({i - 1, j});
            }
            if (i + 1 < rooms.size() && rooms[i + 1][j] == INT_MAX)
            {
                rooms[i + 1][j] = rooms[i][j] + 1;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && rooms[i][j - 1] == INT_MAX)
            {
                rooms[i][j - 1] = rooms[i][j] + 1;
                q.push({i, j - 1});
            }
            if (j + 1 < rooms[0].size() && rooms[i][j+1] == INT_MAX)
            {
                rooms[i][j + 1] = rooms[i][j] + 1;
                q.push({i, j + 1});
            }
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
