//编写一个程序判断给定的数是否为丑数。 
//
// 丑数就是只包含质因数 2, 3, 5 的正整数。 
//
// 示例 1: 
//
// 输入: 6
//输出: true
//解释: 6 = 2 × 3 
//
// 示例 2: 
//
// 输入: 8
//输出: true
//解释: 8 = 2 × 2 × 2
// 
//
// 示例 3: 
//
// 输入: 14
//输出: false 
//解释: 14 不是丑数，因为它包含了另外一个质因数 7。 
//
// 说明： 
//
// 
// 1 是丑数。 
// 输入不会超过 32 位有符号整数的范围: [−231, 231 − 1]。 
// 
// Related Topics 数学 
// 👍 151 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 质数（素数）是指因数只有1和其自身的大于1的自然数
    // 思路一：
    // 先计算所有小于 根号num 的所有质数
    // 然后从7开始遍历所有的质数，如果有能被整除的就不是丑数
    //  num = 214797179 会编译不通过

    bool isUgly1(int num)
    {
        if (num < 1) return false;
        bool isPrim[num+1];
        for (int i = 2; i <= num; ++i) isPrim[i] = true;

        for (int i = 2; i * i <= num; ++i)
        {
            if (isPrim[i])
            {
                for (int j = i * i; j <= num; j += i)
                {
                    isPrim[j] = false;
                }
            }
        }
        for (int i = 7; i <= num; ++i)
        {
            if (isPrim[i] && num % i == 0) return false;
        }
        return true;
    }


    // 思路二：
    // 对数字不断地除以 2、3、5 直到无法整除 则说明不是丑数，如果可以整除说明是丑数
    bool isUgly(int num)
    {
        if (num < 1) return false;
        vector<int> ps = {2, 3, 5};
        while (num > 1)
        {
            bool flag = false;
            for (auto p:ps)
            {
                if (num % p == 0)
                {
                    flag = true;
                    num /= p;
                }
            }
            if (!flag) return false;
        }
        return true;
    }


    // 值得借鉴
    // 对每个数字除到不能再除为止
//    if (num < 1) return false;
//    while (num % 2 == 0) num /= 2;
//    while (num % 3 == 0) num /= 3;
//    while (num % 5 == 0) num /= 5;
//    return num == 1;
};
//leetcode submit region end(Prohibit modification and deletion)
