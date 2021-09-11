// 设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。
// 这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。
//
// 注意：本题相对原题做了扩展 
//
// 示例: 
//
//  输入：4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
// Related Topics 回溯算法 
// 👍 53 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.22
    // 第一次刷完，对这道题目还是很恐惧的，彼时对回溯算法的流程还是不够熟悉
    // 这次做完这个题目明显觉得这个题目是非常简单的，而且代码也一定比之前简练很多，尤其是 isValid 函数
    vector <vector<string>> ans;

    // 如果 board[ir][jc] 位置放置皇后是否和前面放置的不冲突
    bool isValid(vector <string> &board, int ir, int jc)
    {
        // 判断同一列 是否有Q
        // 判断左上方 是否有Q
        // 判断右上方 是否有Q
        int left = jc - 1;
        int right = jc + 1;
        for (int i = ir - 1; i >= 0; --i)
        {
            if (board[i][jc] == 'Q') return false;
            if (left >= 0 && board[i][left] == 'Q') return false;
            if (right < board[0].size() && board[i][right] == 'Q') return false;
            left --;
            right ++;
        }
        return true;
    }

    void backtrack(vector <string> &board, int depth, int n)
    {
        if (depth == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!isValid(board, depth, i)) continue;
            board[depth][i] = 'Q';
            backtrack(board, depth + 1, n);
            board[depth][i] = '.';
        }
    }

    vector <vector<string>> solveNQueens(int n)
    {
        vector <string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
