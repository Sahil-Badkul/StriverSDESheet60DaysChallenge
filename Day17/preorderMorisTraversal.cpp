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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        while(root){
            // case 1. If no left then print ans & move to right
            if(root->left == NULL){
                preorder.push_back(root->val);
                root = root->right;
            }else{
                // extreme right of left subTree 
                TreeNode* prev = root->left;
                while(prev->right && prev->right != root){
                    prev = prev->right;
                }
                // if root pointing to null then link it to curr root and move the left sub tree
                if(prev->right == NULL){
                    prev->right = root;
                    preorder.push_back(root->val);          // print ans before moving to left tree 
                    root = root->left;
                }else{  
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return preorder;
    }
};