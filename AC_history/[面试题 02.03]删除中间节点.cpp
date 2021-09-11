// 实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。
//
// 
//
// 示例： 
//
// 输入：单向链表a->b->c->d->e->f中的节点c
//结果：不返回任何数据，但该链表变为a->b->d->e->f
// 
// Related Topics 链表 
// 👍 71 👎 0


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

    // 二刷，2020.12.19 这道题竟然有点忘了
    // 是个不错的技巧
    // 在当前链表如何删掉这个节点
    // 我们一般要删除一个节点的做法是，利用它的前一个节点 pre->next = pre->next->next
    // 这里的做法就很巧妙，把后一个的值赋值到当前，然后再删掉下一个值，很好
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
