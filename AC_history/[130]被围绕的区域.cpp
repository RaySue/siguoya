//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。 
//
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
//
// 示例: 
//
// X X X X
// X O O X
// X X O X
// X O X X
// 
//
// 运行你的函数后，矩阵变为： 
//
// X X X X
//X X X X
//X X X X
//X O X X
// 
//
// 解释: 
//
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被
//填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 439 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int direction[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, int ii, int jj)
    {
        if (ii < 0 || ii >= board.size() || jj < 0 || jj >= board[0].size() || board[ii][jj] != 'O') return;

        board[ii][jj] = '#';

        for (int i = 0;i < 4; ++i)
        {
            dfs(board, ii + direction[i][0], jj + direction[i][1]);
        }
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board[0].size(); ++i) dfs(board, 0, i);
        for (int i = 0; i < board.size(); ++i) dfs(board, i, board[0].size() - 1);
        for (int i = 0; i < board[0].size(); ++i) dfs(board, board.size() - 1, i);
        for (int i = 0; i < board.size(); ++i) dfs(board, i, 0);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
