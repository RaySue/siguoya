//给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。 
//
// 示例 1： 
//                 11011101111
// 输入: num = 1775(11011101111)
//输出: 8
// 
//
// 示例 2： 
//
// 输入: num = 7(0111)
//输出: 4
// 
// Related Topics 位运算 
// 👍 21 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
//    int l=0,r=0,Max=0;//以0为分界点，L是0左边连续1的数量，R是0右边连续1的数量，Max记录最大值
//    for(int i=0;i<32;i++){
//        if(num&1) r++;
//        else l=r+1,r=0; //当遇见0时， 0的左边连续1的数量等于上一个0右边连续1的数量加一（0本身反转后算一个长度）
//        Max=max(l+r,Max);
//        num>>=1;
//    }
//    return Max;


    // 一刷， 2020.12.30
    // 考虑问题，给你一个vector<int> 里面有若干个 1 和 0，你可以将任意一个 0 变为 1
    // 求你能得到的连续 1 的最大的个数
    int reverseBits(int num)
    {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
