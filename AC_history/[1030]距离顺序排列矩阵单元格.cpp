//
// 给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。
//
// 另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。 
//
// 返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈
// 顿距离，|r1 - r2| + |c1 - c2|。（你可以按任何满足此条件的顺序返回答案。）
//
// 
//
// 示例 1： 
//
// 输入：R = 1, C = 2, r0 = 0, c0 = 0
//输出：[[0,0],[0,1]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
// 
//
// 示例 2： 
//
// [[0,1]
//  [1,0]]
// 输入：R = 2, C = 2, r0 = 0, c0 = 1
//输出：[[0,1],[0,0],[1,1],[1,0]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
//[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
// 
//
// 示例 3： 
//
// 输入：R = 2, C = 3, r0 = 1, c0 = 2
//输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
//其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= R <= 100 
// 1 <= C <= 100 
// 0 <= r0 < R 
// 0 <= c0 < C 
// 
// Related Topics 排序 
// 👍 56 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 直接基于排序的做法，使用lambda表达式
//    Runtime:776 ms, faster than 6.81% of C++ online submissions.
//    Memory Usage:85.7 MB, less than 5.18% of C++ online submissions.
    // Complexity:
    // Time: O((R*C)log(R*C))
    // Space: O(R*C)

    vector <vector<int>> allCellsDistOrder1(int R, int C, int r0, int c0)
    {
        // O(R*C)
        vector <vector<int>> ans;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                ans.push_back({i, j});
            }
        }
        // O( R*Clog(R*C) )
        // lambda 表达式的捕获问题
        auto lambda = [&ans, r0, c0](vector<int> p1, vector<int> p2)
        { return abs(r0 - p1[0]) + abs(c0 - p1[1]) < abs(r0 - p2[0]) + abs(c0 - p2[1]); };
        sort(ans.begin(), ans.end(), lambda);
        return ans;
    }

/**
 *

C++中使用引用作为函数参数的优点
1.传递引用给函数与传递指针的效果是一样的。对形参变量的操作就是对其相应的目标 对象（在主调函数中）的操作所以在内存中并没有产生实参的副本，
 被调函数的形参就成为原来主调函数中的实参变量或对象的一个别名来使用，

 形参变量是实参变量的 副本；
 因此，当参数传递的数据较大时，用引用比 用一般变量传递参数的效率和所占空间都好。

2.使用引用传递函数的参数，它是直接对实参操作；而使用一般变量传递函数的参数，
 当发生函数调用时，需要给形参分配存储单元，
 如果传递的是对象，还将调用拷贝构造函数。

3.使用指针作为函数的参数虽然也能达到与使用引用的效果，
 但是，在被调函数中同样要给形参分配存储单元，且需要重复使用”*指针变量名”的形式进行运算，
 这很容易产生错误且程序的阅 读性较差；另一方面，
 在主调函数的调用点处，必须用变量的地址作为实参。而引用更容易使用，更清晰。

 */
    /*
    [[4,3,2,3,4,5,6],
     [3,2,1,2,3,4,5],
     [2,1,0,1,2,3,4],
     [3,2,1,2,3,4,5],
     [4,3,2,3,4,5,6],
     [5,4,3,4,5,6,7]]
     */

    // 基于桶排序的思想，将数组分到有限数量的桶子里，每个桶子再个别排序。
    // 1. 计算距离矩阵 O(R*C) O(R*C)
    // 2. 将对应的点入桶 O(R*C) O(R*C)
    // 3. 遍历桶得到结果 O(R*C) O(R*C)
    // Complexity:
    // Time: O(R*C)
    // Space: O(R*C)
    vector <vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector <vector<int>> dis(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                dis[i][j] = abs(i - r0) + abs(j - c0);
            }
        }
        int maxDist = abs(0 - r0) + abs(0 - c0);
        maxDist = max(maxDist, abs(R - 1 - r0) + abs(0 - c0));
        maxDist = max(maxDist, abs(0 - r0) + abs(C - 1 - c0));
        maxDist = max(maxDist, abs(R - 1 - r0) + abs(C - 1 - c0));

        vector < vector < vector < int > > > bucket(maxDist + 1);
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                bucket[dis[i][j]].push_back({i, j});
            }
        }

        vector <vector<int>> ans;
        for (int i = 0; i <= maxDist; ++i)
        {
            ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        }

        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
