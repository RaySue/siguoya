// 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。
// 可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
// 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
// 能否在不打破种植规则的情况下 种入 n 朵花？能则返回True
// ，不能则返回False。
//
// 示例 1: 
//
// 
//输入: flowerbed = [1,0,0,0,1], n = 1
//输出: True
// 
//
// 示例 2: 
//
// 
//输入: flowerbed = [1,0,0,0,1], n = 2
//输出: False
// 
//
// 注意: 
//
// 
// 数组内已种好的花不会违反种植规则。 
// 输入的数组长度范围为 [1, 20000]。 
// n 是非负整数，且不会超过输入数组的大小。 
// 
// Related Topics 数组 
// 👍 189 👎 0




//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路一：先对已有的1的两端变为2，然后再对剩下的0进行计算，想复杂了，导致没有成功
//    bool canPlaceFlowers1(vector<int> &flowerbed, int n)
//    {
//        int count = 0;
//        for (int i = 0; i < flowerbed.size(); ++i)
//        {
//            if (flowerbed[i] == 1)
//            {
//                if (i - 1 >= 0) flowerbed[i - 1] = 2;
//                if (i + 1 < flowerbed.size()) flowerbed[i + 1] = 2;
//            }
//        }
//        for (int i = 0; i < flowerbed.size(); ++i)
//        {
//            if (flowerbed[i] == 0) count++;
//        }
//        return false;
//    }


    // 参考答案后的解法
    // 能种花的情况：
    // 1. 右边是 0 的左边界
    // 2. 左右是 0 的情况
    // 3. 左边是 0 的右边界
    // 然后满足上述情况的就开始种，然后继续遍历
    // Complexity:
    // Time O(N)
    // Space O(1)

    // 二刷 2021.01.01 2021年刷的第一题，仿真解法
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int sz = flowerbed.size();
        if (n <= 0) return true;
        if (n > flowerbed.size()) return false;
        if (flowerbed.size() == 1) return flowerbed.back() == 0;
        for (int i = 0; i < sz && n > 0; ++i)
        {
            if (flowerbed[i] != 0) continue;
            if (i == 0 && i + 1 < sz && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            } else if (i == sz - 1 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            } else if (i - 1 >= 0 && i + 1 < sz && (flowerbed[i - 1] == 0) && (flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
