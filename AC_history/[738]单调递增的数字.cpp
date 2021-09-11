// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。） 
//
// 示例 1: 
//
// 输入: N = 10
//输出: 9
// 
//
// 示例 2: 
//
// 输入: N = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 输入: N = 332
//输出: 299
// 
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。 
// Related Topics 贪心算法 
// 👍 92 👎 0



bool operator==(const vector<int> &v1, const vector<int> &v2)
{
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{

public:
    /**
     *

        刚好小于某个数字的最接近的数，再加一些条件

        贪心思路
        1．要使目标数字和 N 最接近，则需要尽可能保持高位数字不动
        2．若某高位数字减 1，则后续所有低位数字都可直接更改为 9，可保持最接近
        3．若低位数字更改为 9，则前一高位数字至少得减 1，可保持最接近

        解题步骤:
        首先从高位开始找到第一个非升序的位，
        将此位减 1，后续所有位改为 9；
        然后从此位开始往前判断看更改后是否满足升序要求，
        若不满足要求则把本位也提升到 9，前一位继续减 1，直到满足升序。 如 110

        110
        109
     */
    vector<int> num2Vec(int n)
    {
        vector<int> ans;
        while (n > 0)
        {
            ans.push_back(n % 10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int monotoneIncreasingDigits(int N)
    {
        vector<int> vec = num2Vec(N);
        vector<int> sortVec = vec;
        sort(sortVec.begin(), sortVec.end());
        if (sortVec == vec) return N;

        for(;;)
        {
            int index = 0;
            for (int i = 0; i < vec.size() - 1; ++i)
            {
                if (vec[i] > vec[i + 1] && index == 0)
                {
                    vec[i] -= 1;
                    index = i + 1;
                }else if (index != 0)
                {
                    vec[i] = 9;
                }
            }
            if (index == 0) break;
            vec.back() = 9;
        }

        int ans = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            ans = vec[i] + ans * 10;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
