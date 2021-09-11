//自除数 是指可以被它包含的每一位数除尽的数。 
//
// 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。 
//
// 还有，自除数不允许包含 0 。 
//
// 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。 
//
// 示例 1： 
//
// 
//输入： 
//上边界left = 1, 下边界right = 22
//输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// 
//
// 注意： 
//
// 
// 每个输入参数的边界满足 1 <= left <= right <= 10000。 
// 
// Related Topics 数学 
// 👍 115 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 题目读三遍，总是记不住，明明说了自除数是不允许包含 0 的，竟然没注意到
    // 读题框架，第一遍读懂意思，第二遍注意条件，第三遍根据题目意思来思考极端情况
    //
    // 编写检查一个数字是否是自除数的函数，注意里面如果出现10，20这样的可能导致residual变量为0，对0取模运算是会报错的
    // 遍历所有元素，计算每个元素是否是自除数
    //
    bool checkSelfDiv(int num)
    {
        int target = num;
        while(target > 0)
        {
            int residual = target % 10;
            if (residual == 0 || num % residual) return false;
            target = target / 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        if (right == 0) return ans;
        for (int i = left; i <= right; ++i)
        {
            bool flag = checkSelfDiv(i);
            if (flag) ans.push_back(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
