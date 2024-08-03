/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 使用双指针计算相邻节点的最小值

    // 用来存放结果
    int result = INT_MAX;
    // 用来记录上一个节点
    TreeNode *pre = nullptr;

    void traversal(TreeNode *cur)
    {
        // 终止条件
        if (cur == nullptr)
            return;
        // 左
        traversal(cur->left);
        // 中：处理
        if (pre != nullptr && cur->val - pre->val < result)
            // 更新
            result = cur->val - pre->val;

        // 更新pre
        pre = cur;

        // 右
        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};
// @lc code=end
