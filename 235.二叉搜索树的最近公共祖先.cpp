/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

// class Solution
// {
// public:
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         // 如果遇到了空节点
//         if (root == nullptr)
//             return nullptr;
//         // 左
//         if (root->val > p->val && root->val > q->val)
//         {
//             return lowestCommonAncestor(root->left, p, q);
//         }
//         // 右
//         else if (root->val < p->val && root->val < q->val)
//         {
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         // 中
//         else
//             return root;
//     }
// };

// 迭代法
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != nullptr)
        {
            // 左
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            // 右
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            // 中
            else
                return root;
        }
        // 如果没有找到
        return nullptr;
    }
};
// @lc code=end
