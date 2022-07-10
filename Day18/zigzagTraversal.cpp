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
Simple level order traversal with reverse each level alternatively
TC : O(n)
SC : O(n)->queue
   : O(size) -> temp vector
*/
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            auto* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(flag) temp[i] = node->data;
            else temp[n-1 -i] = node->data;
        }
        flag = !flag;
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
