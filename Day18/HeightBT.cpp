/// Given level order and inorder of binary tree return height of tree without constructing tree
//==========================================================================================================
/*
Approach 1. 
    serach 1st element of level order recursively while updating level with inorder 
*/
int getIndex(int key,int st, int en, vector<int> &in){
    for(int i = st; i <= en; i++){
        if(in[i] == key) return i;
    }
    return -1;
}
int f(int st, int en, vector<int> in, vector<int> level, int n){
    if(st > en) return 0;
    int getInd = getIndex(level[0], st, en, in);
    if(getInd == -1) return 0;
    int left = getInd - st;
    int right = en - getInd;
    vector<int> newLeftLevel(left);
    vector<int> newRightLevel(right);
    
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = st; j < getInd; j++){
            if(level[i] == in[j]){
                newLeftLevel[k] = level[i];
                k++;
                break;
            }
        }
    }
    k = 0;
    for(int i = 0; i < n; i++){
        for(int j = getInd + 1; j <= en; j++){
            if(level[i] == in[j]){
                newRightLevel[k] = level[i];
                k++;
                break;
            }
        }
    }
    int lHeight = 0, rHeight = 0;
    if(left > 0)
        lHeight = f(st, getInd-1, in, newLeftLevel, left);
    if(right > 0)
        rHeight = f(getInd+1, en, in, newRightLevel, right);
    newLeftLevel.clear();
    newRightLevel.clear();
    return max(lHeight + 1, rHeight + 1);
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	return f(0, N-1, inorder, levelOrder, N) - 1;
}
//========================================================================================================================


/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)
    
    Where N is the total number of nodes in the binary tree.
*/

typedef struct Node{

	// Height stores the height of the current subtree
	int height;
	int leftIndex;
	int rightIndex;
}
Node;

#include <queue>

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	queue< Node > q;

	Node init;

	init.height = 0;
	init.leftIndex = 0;
	init.rightIndex = N - 1;

	q.push(init);

	int maxHeight = 0;

	for(int i = 0; i < N; i++){
		int curr = levelOrder[i];

		Node now = q.front();

		q.pop();

		int currPos;

		/* 
			Iterating from leftIndex to rightIndex to find the position of
		   leveOrder[i] in the inorder array. 
		*/
		for(int j = now.leftIndex; j <= now.rightIndex; j++){
			if(levelOrder[i] == inorder[j]){
				currPos = j;
			}
		}
		
		// There is a left child present.
		if(currPos > now.leftIndex){
			Node newNode;

			// Height will increase by 1, as we are descending 1 level downwards in the tree.
			newNode.height = now.height+1;

			maxHeight = max(maxHeight, newNode.height);

			// New borders of the left subtree in the inorder array.
			newNode.leftIndex = now.leftIndex;
			newNode.rightIndex = currPos-1;

			q.push(newNode);
		}

		// There is a right child present.
		if(currPos < now.rightIndex){
			Node newNode;

			newNode.height=now.height+1;

			maxHeight = max(maxHeight, newNode.height);

			// New borders of the right subtree in the inorder array.
			newNode.leftIndex = currPos+1;
			newNode.rightIndex = now.rightIndex;

			q.push(newNode);
		}
	}
	return maxHeight;
}

//===============================================================================================

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int, int> mp; // Inorder Node value -> index in inorder array
    queue<vector<int>> q; // {start, end, height}
    
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    
    if(mp.find(levelOrder[0]) != mp.end()){
        // root is the last element in inorder traversal then it has no right subtree
        if(mp[levelOrder[0]] == inorder.size()-1) 
            q.push({0, (int)inorder.size()-2, 1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[0]] == 0)
            q.push({1, (int)inorder.size()-1, 1});
        else
        {
            q.push({0, mp[levelOrder[0]]-1, 1});    // left subtree
            q.push({mp[levelOrder[0]]+1, (int)inorder.size()-1, 1});    // right subtree
        }
    }
    int k = 1;
    int ans = 0;
   while(!q.empty())
   {  
    auto temp = q.front();
    q.pop();
    ans = max(ans, temp[2]);
    if(mp.find(levelOrder[k]) != mp.end()){  
        // if it is the leaf node i.e. no left subtree and no right subtree 
        if(temp[0] == temp[1]) 
            ans = max(ans, temp[2] + 1);
        // root is the last element in inorder traversal then it has no right subtree
        else if(mp[levelOrder[k]] == temp[1])
            q.push({temp[0], temp[1]-1, temp[2]+1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[k]] == temp[0])
            q.push({temp[0]+1, temp[1], temp[2]+1});
        else
        {
            q.push({temp[0], mp[levelOrder[k]]-1, temp[2]+1}); // left subtree
            q.push({mp[levelOrder[k]]+1, temp[1], temp[2]+1});    // right subtree
        }
    }
    k++;
   }
   return ans-1;
}