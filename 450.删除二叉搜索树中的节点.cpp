/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 如果根节点为空则没找到返回
        if (root == nullptr)
            return nullptr;
        // 终止条件：找到要删除节点
        if (root->val == key)
        {
            // 要删除的节点是叶子节点则返回nullptr给上一层
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            // 要删除的节点左不为空右为空则返回root->left给上一层
            else if (root->left != nullptr && root->right == nullptr)
                return root->left;
            // 要删除的节点左为空右不为空则返回root->right给上一层
            else if (root->left == nullptr && &root->right != nullptr)
                return root->right;
            // 左右节点都不为空则将右节点作为根节点，将左节点放在右子树中
            else
            {
                // 找到右子树最左边的元素
                TreeNode *cur = root->right;
                while (cur->left != nullptr)
                    cur = cur->left;
                // 将左子树添加到右子树的最左边
                cur->left = root->left;
                // 返回右节点给上一层
                return root->right;
            }
        }
        // 左，如果当前值较大向左寻找
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        // 右，如果当前值较小向右寻找
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // 返回根节点
        return root;
    }
};
// @lc code=end
