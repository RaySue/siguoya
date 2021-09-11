// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例: 
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false 
//
// 
//
// 提示： 
//
// 
// board 和 word 中只包含大写和小写英文字母。 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 1 <= word.length <= 10^3 
// 
// Related Topics 数组 回溯算法 
// 👍 681 👎 0


/**
 *
[["b","a","a","b","a","b"],["a","b","a","a","a","a"],["a","b","a","a","a","b"],["a","b","a","b","b","a"],["a","a","b","b","a","b"],["a","a","b","b","b","a"],["a","a","b","a","a","b"]]
 "aabbbbabbaababaaaabababbaaba"
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
//
//     思路：
//     1. 明确 终止条件：depth 等于 target.size()的时候
//     2. 明确 每步的选择集合，上下左右四个方向
//     3. 明确剪枝情况：
//        3.1 depth > target.size() 的时候直接 return；
//        3.2 搜索边界溢出的时候 continue
//        3.3 如果下一个选择和我们预期的不符 continue
//        3.4 不走回头路，如果下一个选择走过 continue
//
//     4. 遍历整个board，如果发现起始字母和target的首字母相同，开始回溯

    bool ans = false;

    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void backtrack(vector<vector<char>> &board, int ii, int jj, int depth, string &path, string &word)
    {
        if (ans) return;

        if (path == word)
        {
            ans = true;
            return;
        }

        if (ii < 0 || ii >= board.size() || jj < 0 || jj >= board[0].size() || board[ii][jj] == '#') return;

        for (int i = 0; i < 4; ++i)
        {
            if (board[ii][jj] != word[depth]) continue;
            path.push_back(board[ii][jj]);
            board[ii][jj] = '#';
            backtrack(board, ii + direction[i][0], jj + direction[i][1], depth + 1, path, word);
            board[ii][jj] = path.back();
            path.pop_back();
        }

    }

    bool exist(vector <vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    string path;
                    backtrack(board, i, j, 0, path, word);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
