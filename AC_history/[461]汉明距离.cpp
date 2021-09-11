//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。 
//
// 给出两个整数 x 和 y，计算它们之间的汉明距离。 
//
// 注意： 
//0 ≤ x, y < 231. 
//
// 示例: 
//
// 
//输入: x = 1, y = 4
//
//输出: 2
//
//解释:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑
//
//上面的箭头指出了对应二进制位不同的位置。
// 
// Related Topics 位运算 
// 👍 341 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 汉明距离看似简单，实则暗藏玄机
    // 负数的情况 x^y 的结果必须要转成 unsigned int
    //
    int hammingDistance(int x, int y)
    {
        int distance = 0;
        x ^= y;
        while(x > 0)
        {
            x &= (x - 1);
            distance++;
        }
        return distance;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
