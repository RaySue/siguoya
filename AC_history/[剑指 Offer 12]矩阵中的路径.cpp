// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
// 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
//
// [["a","b","c","e"], 
// ["s","f","c","s"],
// ["a","d","e","e"]]
//
// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。 
//
// 
//
// 示例 1： 
//
// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "A
//BCCED"
//输出：true
// 
//
// 示例 2： 
//
// 输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 深度优先搜索 
// 👍 204 👎 0



//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    //#define For(i, n) for(int i=1;i<=n;i++)
#define Bound(i, j) if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
#define For(s, n) for(int p=s;p<n;p++)
#define ForRow(n) for(int i=0;i<n;i++)
#define ForCol(n) for(int j=0;j<n;j++)
#define Fork(i, k, n) for(int i=k;i<=n;i++)
#define Rep(i, n) for(int i=0;i<n;i++)
#define ForD(i, n) for(int i=n;i;i--)
#define RepD(i, n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (2*100000+10)

    long long mul(long long a, long long b)
    { return (a * b) % F; }

    long long add(long long a, long long b)
    { return (a + b) % F; }

    long long sub(long long a, long long b)
    { return (a - b + (a - b) / F * F + F) % F; }

public:

    /**
     *

     P(A|B) = P(A,B) / P(B)

     p(B|A) = P(A,B) / P(A)

     P(A,B) = P(A|B) * p(B) = p(B|A) * P(A)

     p(Bi|A) = p(A|Bi) * p(Bi) / P(A)

     p(A) = sum p(A|Bj) * P(Bj)

     p(类别1|特征i) = p(特征i|类别1) * p(特征i) / P(特征i)

     p(特征i) = sum P(特征i|类别j) * p(类别j)

     p(类别1|特征) = p(类别1|特征1) * p(类别1|特征2) * ... * p(类别1|特征n)
     p(类别2|特征) = p(类别2|特征1) * p(类别2|特征2) * ... * p(类别2|特征n)

     *
     */

    // 思路：回溯算法
    // 选择列表 up down left right
    // 终止条件 path == word
    // 剪枝 ：
    // 1. 越界
    // 2. 第 path[i] != word[i]
    // 3. board[i][j] 不是字母，利用board自身做防止走回头路


    bool ans = false;

    int direction[4][2] = {{-1, 0},
                           {1,  0},
                           {0,  -1},
                           {0,  1}};

    void backtrack(vector <vector<char>> &board, int ii, int jj, int depth,  string& path, string& word)
    {
        if (ans) return;
        if (path == word)
        {
            ans = true;
            return;
        }
        if (ii < 0 || ii >= board.size() || jj < 0 || jj >= board[0].size()) return;
        for (int i = 0; i < 4; ++i)
        {
            if (board[ii][jj] == '#' || board[ii][jj] != word[depth]) continue;
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
                    int depth = 0;
                    backtrack(board, i, j, depth, path, word);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
