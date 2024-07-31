/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // 返回类型和参数
    int minDepth(TreeNode *root)
    {
        // 终止条件
        if (root == nullptr)
            return 0;
        // 后序遍历
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // 如果右边为空，只有左子树
        if (root->left != nullptr && root->right == nullptr)
            return left + 1;
        // 如果左边为空，只有右子树
        if (root->left == nullptr && root->right != nullptr)
            return right + 1;
        // 左右子树不为空
        return min(left, right) + 1;
    }
};
// @lc code=end
