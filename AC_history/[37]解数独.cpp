// 编写一个程序，通过填充空格来解决数独问题。
//
// 一个数独的解法需遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 空白格用 '.' 表示。 
//
// 
//
// 一个数独。 
//
// 
//
// 答案被标成红色。 
//
// 提示： 
//
// 
// 给定的数独序列只包含数字 1-9 和字符 '.' 。 
// 你可以假设给定的数独只有唯一解。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 回溯算法 
// 👍 683 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 解数独
    bool backtracking(vector <vector<char>> &board) {
        for (int i = 0; i < board.size(); i++)  // 遍历行
        {
            for (int j = 0; j < board[0].size(); j++)  // 遍历列
            {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++){     // (i, j) 这个位置放k是否合适
                    if (isValid(i, j, k, board)){
                        board[i][j] = k;                      // 放置k
                        if (backtracking(board)) return true; // 如果找到合适一组立刻返回
                        board[i][j] = '.';                    // 回溯，撤销k
                    }
                }
                return false;  // 9个数都试完了，都不行，那么就返回false
            }
        }
        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
    }
    bool isValid(int row, int col, char val, vector <vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)  if (board[row][i] == val) return false; // 判断行里是否重复
        for (int j = 0; j < 9; j++)  if (board[j][col] == val) return false; // 判断列里是否重复
        // 判断9方格里是否重复
        int startRow = (row / 3) * 3; int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++){
            for (int j = startCol; j < startCol + 3; j++){
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector <vector<char>> &board)
    {
        backtracking(board);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
