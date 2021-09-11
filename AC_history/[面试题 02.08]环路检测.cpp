// 给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
//
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的
// 位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [3,2,0,-4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 示例 3： 
//
// 
//
// 
//输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。 
//
// 
//
// 进阶： 
//
// 
// 你是否可以不用额外空间解决此题？ 
// 
//
// 
// Related Topics 链表 
// 👍 47 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // base line 方法是使用 hash map 额外空间
    // 不使用额外空间的方法，先用快慢指针找到环的交点，然后让任意指针回到原点，然后再一起步长为1的行进，相与处就是入环处
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next) return nullptr; // 非常必要的异常情况检测， 如果有环，即使一个节点也不会出现 head->next 为空
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || slow != fast) return nullptr;  // 出来的结果，必须保证slow == fast，即必须有环
        fast = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
