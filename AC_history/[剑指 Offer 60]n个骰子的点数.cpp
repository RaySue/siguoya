// 把 n 个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//
// 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1: 
//
// 输入: 1
//输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
// 
//
// 示例 2: 
//
// 输入: 2
//输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
//
// 
//
// 限制： 
//
// 1 <= n <= 11 
// 👍 146 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 一刷 2021.01.07 利用 python
    // 思路：
    // 对 n 次的结果进行顺序计算，利用 tree map 存储元素
    // 1. 初始化概率列表 ini 长度为 6，[1/6, ..., 1/6]
    // 2. 两两遍历，笛卡尔积，注意 k1 + k2 可能是重复的，所以概率要累加
    def dicesProbability(n):
        ini = OrderedDict()
        for i in range(1, 7, 1):
            ini[i] = 1 / 6
        if n == 1:
            return list(ini.values())
        ret = ini
        for i in range(n - 1):
            tmp = OrderedDict()
            for k1, v1 in zip(list(ret.keys()), list(ret.values())):
                for k2, v2 in ini.items():
                    if k1 + k2 in tmp:
                        tmp[k1 + k2] = v1 * v2 + tmp[k1 + k2]
                    else:
                        tmp[k1 + k2] = v1 * v2
            ret = tmp
        return list(ret.values())


    vector<double> dicesProbability(int n)
    {



    }
};
//leetcode submit region end(Prohibit modification and deletion)
