/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

int getMaxWidth(TreeNode<int> *root)
{
//     vector<int> ans;
    // return the maximum size of level in level order traversal
    int ans = 0;
    if(!root) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans = max(ans, n);
        for(int i = 0; i < n; i++){
            root = q.front();
            q.pop();
//             ans.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
    return ans;
}