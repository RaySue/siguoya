// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。 
//
// 
//
// 进阶： 
//
// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。 
//
// 
//
// 示例： 
//
// 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7
// 
// Related Topics 链表 
// 👍 307 👎 0


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

    // 思路：
    // 方法一：
    // 利用 vector<int> 分别存储 l1 和 l2，再做加法
    // 然后再把结果赋值到新的 ListNode
    // 再对 ListNode 进行反转

    // 方法二：
    // 不对最终的结果进行反转，而是在添加的过程中，每个元素就是反着的，类似于 res = s + res;
    // 倒序的过程：你的next指向我，然后再把你的值给我即可

    // 也有用stack来存储两个链表的结果的
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        vector<int> nums1, nums2;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        while (ptr1 != nullptr)
        {
            nums1.push_back(ptr1->val);
            ptr1 = ptr1->next;
        }
        while (ptr2 != nullptr)
        {
            nums2.push_back(ptr2->val);
            ptr2 = ptr2->next;
        }
        int p1 = nums1.size() - 1, p2 = nums2.size() - 1;
        // 反转的尾部
        ListNode *ptr = nullptr;
        int carry = 0;
        while (p1 >= 0 || p2 >= 0 || carry > 0)
        {
            int n1 = p1 >= 0 ? nums1[p1--] : 0;
            int n2 = p2 >= 0 ? nums2[p2--] : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            // 倒序的过程
            auto nextNode = new ListNode(tmp % 10);
            nextNode->next = ptr;
            ptr = nextNode;
        }
        return ptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
