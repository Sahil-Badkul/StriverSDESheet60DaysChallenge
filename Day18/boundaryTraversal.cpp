/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>* root){
    return (!root->left and !root->right);
}
void addleft(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isleaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void addRight(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1; i >= 0; i--){
        ans.push_back(temp[i]);
    }
}
void addLeaf(TreeNode<int>* root, vector<int>&ans){
    if(isleaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left, ans);
    if(root->right) addLeaf(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    if(isleaf(root)) return ans;
    addleft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);
    return ans;
    
}