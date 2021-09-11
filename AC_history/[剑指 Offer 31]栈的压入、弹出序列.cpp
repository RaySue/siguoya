// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
// 序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
//
// 
//
// 示例 1： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
//输出：true
//解释：我们可以按以下顺序执行：
//push(1), push(2), push(3), push(4), pop() -> 4,
//push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// 
//
// 示例 2： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
//输出：false
//解释：1 不能在 2 之前弹出。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= pushed.length == popped.length <= 1000 
// 0 <= pushed[i], popped[i] < 1000 
// pushed 是 popped 的排列。 
// 
//
// 注意：本题与主站 946 题相同：https://leetcode-cn.com/problems/validate-stack-sequences/ 
// 👍 96 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 一刷 2021.01.22
    // 早上上厕所的时候看 剑指 offer 看懂了这道题目的意思：
    // 按照 pushed 的顺序入栈，如果入栈过程中某个栈顶元素恰好和 poped 栈顶元素，首个元素相同，那么就pop
    // 如果最终 pushed 的所有数字都能够顺利的入栈并出栈，那么返回 true
    // 否则返回 false

    // 利用虚拟栈来解决这个问题
    // 对 pushed 的元素执行入栈操作，入栈之后就判断栈顶元素是否和popped的第 '首个元素' （用 p 来维护） 是否相等
    // 如果相等，那么继续出栈，直到不相等
    // 然后继续对 pushed 进行虚拟入栈，执行上述步骤
    // 判断最终的 虚拟栈 是否为空，即可判断 压入学列 和 弹出序列是否匹配
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> dummySta;
        int p = 0;
        for (int i = 0; i < pushed.size(); ++i)
        {
            dummySta.push(pushed[i]);
            while (!dummySta.empty() && p < popped.size() && dummySta.top() == popped[p])
            {
                dummySta.pop();
                p++;
            }
        }
        return dummySta.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
