/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 虚拟头节点
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        // 用来遍历的cur
        ListNode *cur = dummyHead;

        // 奇数和偶数条件下都要成立
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            // cur会被修改，所以保存一号和三号节点
            ListNode *temp1 = cur->next;
            ListNode *temp3 = cur->next->next->next;
            // cur指向第二个节点
            cur->next = cur->next->next;
            // 第二个节点指向第一个
            cur->next->next = temp1;
            // 第一个节点指向第三个
            temp1->next = temp3;

            // 更新cur的位置
            // 让它指向第三个节点的前面(一号节点的位置)
            cur = temp1;
        }
        // 返回头节点
        return dummyHead->next;
    }
};
// @lc code=end
