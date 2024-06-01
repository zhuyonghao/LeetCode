/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 虚拟头节点为了方便头节点操作
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;

        // 定义快慢指针
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        // 快指针先走n+1
        n++;
        while (n)
        {
            fast = fast->next;
            n--;
        }
        // 快慢指针同时走
        // 当快指针走到nullptr
        // 此时慢指针走到目标节点前面
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除目标节点
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        // 释放节点
        delete tmp;
        // 返回头节点
        return dummyHead->next;
    }
};
// @lc code=end
