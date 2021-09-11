//中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。 
//
// 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。 
//
// 
//
// 示例 1: 
//
// 输入: num = "69"
//输出: true
// 
//
// 示例 2: 
//
// 输入: num = "88"
//输出: true 
//
// 示例 3: 
//
// 输入: num = "962"
//输出: false 
//
// 示例 4： 
//
// 输入：num = "1"
//输出：true
// 
// Related Topics 哈希表 数学 
// 👍 18 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    char symmetry(char a)
    {
        switch (a)
        {
            case '0':
                return '0';
            case '1':
                return '1';
            case '6':
                return '9';
            case '8':
                return '8';
            case '9':
                return '6';

            default:
                return '#';
        }
    }

    // 注意是整组数旋转了 180 度，那就是每个数翻转的同时整个数组翻转
    bool isStrobogrammatic(string num)
    {
        string newNum = "";
        for(int i = num.size() - 1; i >= 0; --i)
        {
            char m = symmetry(num[i]);
            if (m != '#') newNum.push_back(m);
        }
//        reverse(newNum.begin(), newNum.end());   // 比较耗时
        return newNum == num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
