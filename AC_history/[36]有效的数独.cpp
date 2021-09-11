//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 
//
// 上图是一个部分填充的有效的数独。 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 示例 1: 
//
//
// 输入:
//[
//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//[
//  ["8","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: false
//解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。 
//
// 说明: 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 给定数独序列只包含数字 1-9 和字符 '.' 。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 
// 👍 442 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.23
    //
    // 依稀记得一刷的时候是看了题解，感觉一次遍历就可以解决这个问题，比较神奇，利用hash_map 或 hash_set
    //
    // 一次遍历完成该算法，对每行、每列和每3x3个格子计算是否有重复数字即可
    //
    // 二刷的时候我看题解有高手使用 位运算，我之前是想用 bucket 来代替 hash_set 的，后来发现需要vector<vector<int>>
    // 索性就是用位运算了，因为位运算相当于一个整数就可以存储32位，相当于一个 bucket，所以我们每次只需要利用位移运算将出现的值存在，然后再判断那个位置是否有值就可以
    bool isValidSudoku1(vector <vector<char>> &board)
    {
//        vector <unordered_set<char>> row(9);
//        vector <unordered_set<char>> col(9);
//        vector <unordered_set<char>> grid(9);
        vector<int> row(9);
        vector<int> col(9);
        vector<int> grid(9);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.') continue;
                int tmp = board[i][j] - '0';
                int gridIdx = i / 3 * 3 + j / 3; // 二维：[i / 3][j / 3]; 一维：i / 3 * 3 + j / 3
                if ((row[i] & (1 << tmp)) != 0 || (col[j] & (1 << tmp)) != 0 || (grid[gridIdx] & (1 << tmp)) != 0)
                    return false;
                // 这里可以用 |= 也可以用 += ，提交显示 += 更快？？
                row[i] += (1 << tmp);
                col[j] += (1 << tmp);
                grid[gridIdx] += (1 << tmp);
            }
        }
        return true;
    }

    bool isValidSudoku2(vector <vector<char>> &board)
    {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        vector<unordered_set<int>> grid(9);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int tmp = board[i][j] - '0';
                    if (row[i].count(tmp)) return false; else row[i].insert(tmp);
                    if (col[j].count(tmp)) return false; else col[j].insert(tmp);
                    if (grid[i / 3 * 3 + j / 3].count(tmp)) return false; else grid[i / 3 * 3 + j / 3].insert(tmp);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector <vector<char>> &board)
    {
        vector<int> row(9);
        vector<int> col(9);
        vector<int> grid(9);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int tmp = board[i][j] - '0';
                    int b = (1 << tmp);
                    if (row[i] & b) return false; else row[i] += b;
                    if (col[j] & b) return false; else col[j] += b;
                    if (grid[i / 3 * 3 + j / 3] & b) return false; else grid[i / 3 * 3 + j / 3] += b;
                }
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
