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
/*
Efficient approach to solve the problem is using postorder traversal 
Intution is to return max diameter of any vertex which is sum of left subtree + right subtree
So just calculate hight of subtree in every vertex and update diameter
*/
class Solution {
public:
    int height(TreeNode* root, int &dia){
        if(root == NULL) return 0;
        int lh = 0, rh = 0;
        if(root->left) lh = height(root->left, dia);
        if(root->right) rh = height(root->right, dia);
        dia = max(dia, lh+rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        int h = height(root, dia);
        return dia;
    }
};