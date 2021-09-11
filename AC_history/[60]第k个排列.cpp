//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法 
// 👍 347 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    vector<string> debugAns;

    string ans;
    int ptr = 0;
    bool final = false;

    // base 解法
    // 时间复杂度 O(n!)  Time out
    void backtrack(int n, int k, int depth, vector<bool> isVis, string path)
    {
        if (final) return;
        if (depth == n)
        {
            debugAns.push_back(path);
            ans = path;
            ptr++;
            if (ptr == k)
            {
                final = true;
                ans = path;
            }
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (isVis[i - 1]) continue;
            char a = (char) (i + '0');
            path.push_back(a);
            isVis[i - 1] = true;
            backtrack(n, k, depth + 1, isVis, path);
            isVis[i - 1] = false;
            path.pop_back();
        }
    }


    string getPermutation1(int n, int k)
    {
        vector<bool> isVis(n, false);
        string path;
        backtrack(n, k, 0, isVis, path);

        for (auto ss : debugAns)
        {
            cout << ss << endl;
        }

        return ans;
    }

// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------


    string getPermutation(int n, int k)
    {
        // 构造 n 的阶乘的列表
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string ans;

        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            int order = k / factorial[n - i] + 1;

            for (int j = 1; j <= n; ++j)
            {
                order -= valid[j];
                if (!order)
                {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
