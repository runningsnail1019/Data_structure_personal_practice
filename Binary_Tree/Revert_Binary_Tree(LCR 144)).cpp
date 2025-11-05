/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flipTree(TreeNode* root) {
        if (root != nullptr) {
            flipTree(root->left);//其中一个为空也要交换（原写法为if(root->left)...）
            flipTree(root->right);
            TreeNode* p;
            p = root->left;//注意此处要包含在if中防止nullptr->nullptr发生
            root->left = root->right;
            root->right = p;
        }

        return root;
    }
};
