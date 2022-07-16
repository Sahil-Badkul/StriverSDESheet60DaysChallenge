/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
typedef vector<int> vi;
TreeNode<int> *build(vi &inorder, int inStart, int inEnd,
                     vi &preorder, int preStart,int preEnd, map<int, int> &inMap){
    if(inStart > inEnd || preStart > preEnd) return NULL;
    // create new root
    TreeNode<int> *root = new TreeNode<int> (preorder[preStart]);
    // curr index of root in inorder traversal
    int ele = inMap[root->data];
    // left is for defining new preorder start and end.
    int left = ele - inStart;
    // Note : Keep in mind to set to new preStart, preEnd, inStart, inEnd of preorder and inorder.
    root->left = build(inorder, inStart, ele-1, preorder, preStart+1, preStart+left, inMap);
    root->right = build(inorder, ele+1, inEnd, preorder, preStart+left+1, preEnd, inMap);
    return root;
}
/*
left = ele - inStart
Subtree left and right 
left -> inorder --> inStart, ele-1
     -> preorder--> preStart+1, preStart+left

right -> inorder --> ele+1, inEnd
      -> preorder--> preStart+left+1, preEnd
*/
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int,int> inMap;
    for(int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    return build(inorder, 0, inorder.size()-1, 
                               preorder, 0, preorder.size()-1, inMap);
}