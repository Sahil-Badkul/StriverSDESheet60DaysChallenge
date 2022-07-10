/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode*left = lowestCommonAncestor(root->left, p, q);
        TreeNode*right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};

//===============================================================================



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

TreeNode<int>* lca(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if(root == NULL || root == p || root == q){
        return root;
    }
    TreeNode<int>*left = lca(root->left, p, q);
    TreeNode<int>*right = lca(root->right, p, q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}
TreeNode<int>* findNode(TreeNode<int>* root, int x){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        auto* node = q.front();
        q.pop();
        if(node->data == x) return node;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	TreeNode<int>* p = findNode(root, x);
    TreeNode<int>* q = findNode(root, y);
    TreeNode<int>* ans = lca(root, p, q);
    return ans->data;
}

//==================================================================

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL) return -1;
    if(root->data == x or root->data == y){
        return root->data;
    }
    int a = lowestCommonAncestor(root->left, x, y);
    int b = lowestCommonAncestor(root->right, x, y);
    if(a == x and b == y or a == y and b == x){
        return root->data;
    }
    else if(a == -1 and b == -1){
        return -1;
    }else if(a == -1 and b != -1){
        return b;
    }else if(a != -1 and b == -1){
        return a;
    }
}