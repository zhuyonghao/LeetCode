/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // 如果根节点为空则返回
        if (root == nullptr)
            return nullptr;

        // 如果当前值较大向左寻找有没有在区间内的
        // 使用递归继续修剪
        if (root->val > high)
            return trimBST(root->left, low, high);

        // 如果当前值较小则向右寻找继续修剪
        if (root->val < low)
            return trimBST(root->right, low, high);

        // 将修剪后的左子树和右子树赋值给新的根节点
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        // 返回根节点
        return root;
    }
};
// @lc code=end
