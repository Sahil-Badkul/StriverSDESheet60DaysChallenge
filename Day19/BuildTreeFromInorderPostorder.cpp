/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
typedef vector<int> vi;
TreeNode<int>* makeTree(vi &postOrder, int postStart, int postEnd, vi &inOrder, int inStart, int inEnd, map<int,int> &inMap){
    if(postStart > postEnd || inStart > inEnd) return NULL;
    TreeNode<int>* root = new TreeNode<int>(postOrder[postEnd]);
    int inRoot = inMap[root->data];
    int left = inRoot - inStart;
    root->left = makeTree(postOrder, postStart, postStart+left-1, 
                         inOrder, inStart, inRoot-1, inMap);
    root->right = makeTree(postOrder, postStart+left, postEnd-1, 
                          inOrder, inRoot+1, inEnd, inMap);    
    return root;    
}
/*
left = ele - inStart
Subtree left and right 
left -> inorder --> inStart, ele-1
     -> postorder--> postorder, postorder+left-1

right -> inorder --> ele+1, inEnd
      -> postorder--> postorder+left, postorder-1
*/
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	map<int,int> inMap;
    for(int i = 0; i < inOrder.size(); i++){
        inMap[inOrder[i]] = i;
    }
    return makeTree(postOrder, 0, postOrder.size()-1, inOrder, 0, inOrder.size()-1, inMap);
}
