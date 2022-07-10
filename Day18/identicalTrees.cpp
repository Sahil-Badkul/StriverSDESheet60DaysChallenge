/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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
    };

***********************************************************/
/*
pre order traversal
1. check if any tree is NULL then they are same or not
2. check for there value 
3. recursion
TC : O(n)
SC : O(h) auxilary stack space.
*/
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL or root2 == NULL) return root1 == root2;
    if(root1->data != root2->data) return false;
    return (identicalTrees(root1->left, root2->left) &&
           identicalTrees(root1->right, root2->right));
}