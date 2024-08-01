/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode *root, vector<int> &path, vector<string> &result)
    {
        // 中: 提前push，因为没有遇到空节点
        path.push_back(root->val);
        // 终止条件叶子节点为空
        if (root->left == nullptr && root->right == nullptr)
        {
            // 将path转换为string
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]) + "->";
            }
            // 将path最后一位加入
            sPath += to_string(path[path.size() - 1]);
            // 放入结果中
            result.push_back(sPath);
            return;
        }
        // 左
        if (root->left)
        {
            // 递归
            traversal(root->left, path, result);
            // 回溯
            path.pop_back();
        }
        if (root->right)
        {
            // 递归
            traversal(root->right, path, result);
            // 回溯
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        // 用来存放单个路径
        vector<int> path;
        // 用来存放结果
        vector<string> result;
        // 如果根节点为空则返回
        if (root == nullptr)
            return {};
        // 前序遍历
        traversal(root, path, result);
        return result;
    }
};
// @lc code=end
