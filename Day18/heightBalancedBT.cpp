/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
/*
A Tree is said to be height balance if difference of leftsubtree & righsubtree is not more than 1
 So simple check this for every node by calculating height.
*/
int helper(BinaryTreeNode<int>* root){
        if(root == NULL) return 0;
        int lh = 0, rh = 0;
        if(root->left) lh = helper(root->left);
        if(lh == -1) return -1;
        if(root->right) rh = helper(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    int ans = helper(root);
    return ans == -1 ? false : true;
}