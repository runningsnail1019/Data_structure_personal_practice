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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode** base=(TreeNode**)malloc(sizeof(TreeNode*)*100);
        TreeNode** top=base;
        vector<int> result;
        TreeNode*p=root;
        TreeNode*q=root;
        while(p!=nullptr||top!=base){
            while(p){
                *top=p;
                top++;
                p=p->left;
            }

            top--;
            p=*top;
            if(p->right!=nullptr&&p->right!=q){//必定上一次访问的是右侧根节点或者右侧为空这一次才能访问当前节点，否则重新入栈
                *top=p;
                top++;
                p=p->right;
            }

            else{
                result.push_back(p->val);
                q=p;
                p=nullptr;
            }
        }
        return result;
    }
};
