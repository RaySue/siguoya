//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 回溯算法 
// 👍 727 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 三刷 2021.01.21
    // 思路：
    // 1. 先定义棋盘格子
    // 2. 每次选择在一行中选择位置判断该位置是否可以放置 皇后 剪枝
    // 3. 在一行中的一个位置上放置皇后，做出选择
    // 4. 递归的深度 depth 恰好等于 n，说明此时的放置是有效的，存入 ans 中
    // 5. 如果某行无法放置了那么就返回上一次的选择，重新选择，回溯

    vector<vector<string>> ans;

    // 1. 同一列不能有 Q
    // 2. 左上方不能有 Q
    // 3. 右上方不能有 Q
    bool isValid(vector<string> &board, int i, int j)
    {
        int c = j;
        int lu = c;
        int ru = c;
        for (int r = i - 1; r >= 0; --r)
        {
            lu--;
            ru++;
            if (board[r][j] == 'Q') return false;
            if (lu >= 0 && board[r][lu] == 'Q') return false;
            if (ru < board.size() && board[r][ru] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string> &board, int depth)
    {
        if (depth == board.size())
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); ++i)
        {
            if(!isValid(board, depth, i)) continue;
            board[depth][i] = 'Q';
            backtrack(board, depth + 1);
            board[depth][i] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
