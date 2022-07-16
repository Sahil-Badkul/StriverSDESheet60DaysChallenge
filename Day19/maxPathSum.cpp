/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
typedef long long int lli;
lli maxSum(TreeNode<int>*root, lli &sum){
    if(!root) return 0;
    lli left = maxSum(root->left, sum);
    if(left < 0) left = 0;
    lli right = maxSum(root->right, sum);
    if(right < 0) right = 0;
    sum = max(sum, root->val+left+right);
    return root->val + max(left, right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || !root->left || !root->right) return -1;
    lli sum = -1;
    lli ans = maxSum(root, sum);
    return sum;
}