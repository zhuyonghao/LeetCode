/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 两者都为空则相等
        if (left == nullptr && right == nullptr)
            return true;
        // 一方为空则不相等
        else if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        // 值不同则不相等
        else if (left->val != right->val)
            return false;
        // 值相同则递归检查判断外侧和内测的子树是否相等
        return compare(left->left, right->right) && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // 如果根节点为空则对称
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};
// @lc code=end
