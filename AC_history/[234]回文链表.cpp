//请判断一个链表是否为回文链表。 
//
// 示例 1: 
//
// 输入: 1->2
//输出: false 
//
// 示例 2: 
//
// 输入: 1->2->2->1
//输出: true
// 
//
// 进阶： 
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 链表 双指针 
// 👍 627 👎 0


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


    // base 方法是直接转 vector 然后再判断
    // 进阶方法就是使用递归
    bool isPalindrome1(ListNode *head)
    {
        if (!head) return true;
        pre = head;
        return dfs(head);
    }

    bool dfs(ListNode *head)
    {
        if (!head) return true;
        bool flag = dfs(head->next);
        flag &= (head->val == pre->val);
        pre = pre->next;
        return flag;
    }

    // 快慢指针，一半遍历翻转，然后再从中心向两端判断
    // [1, 2, 3]
    // [1, 2, 3, 4]
    bool isPalindrome(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* p = head;
        ListNode* pre = nullptr;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            p->next = pre;
            pre = p;
            p = slow;
        }
        // 越过奇数节点
        if (fast) slow = slow->next;

        while(pre)
        {
            if (pre->val != slow->val) return false;
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }


private:

    ListNode* pre;

};
//leetcode submit region end(Prohibit modification and deletion)
