/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 头节点不可以为空
        // 头节点为目标值
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        // 要删除元素需要知道上一个节点
        ListNode *cur = head;
        // 当前节点不为空
        // 下一个节点为空此时结束
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                // 下一节点为目标值
                cur->next = cur->next->next;
            }
            // 如果不等于后移一位
            else
                cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
