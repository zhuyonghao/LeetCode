/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 终止条件: 遇到空节点
        if (root == nullptr)
            return root;
        // 遇到该节点则返回
        if (root == p || root == q)
            return root;
        // 左
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 右
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 后序：向上返回
        // 如果左右子树都有返回值则根节点是共同祖先
        if (left != nullptr && right != nullptr)
            return root;
        // 左子树有返回值则返回左子树
        else if (left != nullptr && right == nullptr)
            return left;
        // 右子树有返回值则返回右子树
        else if (left == nullptr && right != nullptr)
            return right;
        // 左右子树都为空
        else
            return nullptr;
    }
};
// @lc code=end
