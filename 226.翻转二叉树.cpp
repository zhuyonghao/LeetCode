/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    // 参数和返回类型
    TreeNode *invertTree(TreeNode *root)
    {
        // 终止条件
        if (root == nullptr)
            return root;
        // 处理逻辑
        // 前序：中左右
        // 后序：左右中
        // 中序：左边处理了两次
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        // 返回翻转后的根节点
        return root;
    }
};
// @lc code=end
