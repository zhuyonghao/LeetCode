/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 新建二维数组存放结果
        vector<vector<int>> result;

        // 新建队列存放每层元素
        queue<TreeNode *> q;

        // 如果根节点为空则返回{}
        if (root == nullptr)
            return result;

        // 向队列中放入头节点
        q.push(root);

        // 当队列不为空时pop元素
        while (!q.empty())
        {

            // 要pop掉元素的个数
            int size = q.size();

            // 每次执行外层while都会新建一个level数组
            // 用来存放每层的元素
            vector<int> level;

            // 执行次数为size
            // q.size()--表达式不可赋值
            while (size--)
            {

                // 获取要删去的节点
                TreeNode *current = q.front();

                // 删除掉队列头节点
                q.pop();

                // 将结果存放在level中
                level.push_back(current->val);

                // 将当前节点的左右节点加入到队列中
                // 左节点不为空加入
                if (current->left)
                    q.push(current->left);

                // 右节点不为空加入
                if (current->right)
                    q.push(current->right);
            }

            // 将该层元素放入结果数组中
            result.push_back(level);
        }
        return result;
    }
};
// @lc code=end
