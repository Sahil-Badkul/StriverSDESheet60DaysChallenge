/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
#include<bits/stdc++.h>
bool helper(BinaryTreeNode<int> *root1, BinaryTreeNode<int> * root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2 || root1->data != root2->data) return false;
    bool one = helper(root1->left, root2->right);
    bool two = helper(root1->right, root2->left);
    return one && two;    
}
bool iterative(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        auto *root1 = q.front(); q.pop();
        auto *root2 = q.front(); q.pop();
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->data != root2->data) return false;
        q.push(root1->left);
        q.push(root2->right);
        q.push(root1->right);
        q.push(root2->left);
    }
    return true;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
//     return helper(root->left, root->right);
    return iterative(root);
}