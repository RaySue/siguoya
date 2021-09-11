//编写一个函数，检查输入的链表是否是回文的。 
//
// 
//
// 示例 1： 
//
// 输入： 1->2
//输出： false 
// 
//
// 示例 2： 
//
// 输入： 1->2->2->1
//输出： true 
// 
//
// 
//
// 进阶： 
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 链表 
// 👍 38 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:

    ListNode *first;

    // 二刷 2020.12.30
    // 利用递归来解决，先递归到达最后一个节点，然后和第一个节点对比
    // 出栈后到达倒数第二个节点，first也在上次出栈前进入了next
    // 缺点是需要从头比较到尾
    bool isPalindrome(ListNode *head)
    {
        if (!head) return true;
        first = head;
        return traverse(head);
    }

    bool traverse(ListNode *head)
    {
        if (!head) return true;
        bool flag = traverse(head->next);
        flag &= (head->val == first->val);
        first = first->next;
        return flag;
    }


    // 一边遍历，一边逆序

};
//leetcode submit region end(Prohibit modification and deletion)
