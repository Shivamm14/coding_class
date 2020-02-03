#include<bits/stdc++.h>
using namespace std;


struct node {
	int data;
	node * left;
	node * right;
}
// returns true if target exist in the tree
// else returns false;


bool isLeaf(node * root){
	if(!root->left and !root->right) 
		return true;
	return false;
}

bool lookup(node * root, int target){
	 // base case
	if(node == NULL){
		return false;
	}
	// recursive case
	else{
		if(node->data == target){
			return true;
		}
		if(node->data > target) 
			return lookup(root->left, target);
		return lookup(root->right, target);
	}
}

node * NewNode(int x){
	node * newnode = new node();
	newnode->data=x;
	return  newnode;
}
//  bst insert
node * insert(node * root, int x){
	// base case
	if(root==NULL){
		return NewNode(x);
	}
	// recursive case
	else{
		if(root->data < x){
				root->right = insert(root->right, x);
		}else{
			root->left = insert(root->left, x);
		}
	}
	return root;
}
// 
node * build123(){
	node *root = NewNode(2);
	root->left = NewNode(1);
	root->right = NewNode(3);\
	return root;
}

// return number of nodes in the tree
int size(node *root){
		// base 
		if(root==NULL){
			return 0;
		}// recursive
		else{
			return 1 + size(root->left) + size(root->right);
		}
}







// returns max depth of the tree
int maxDepth(node *root){
	// base 
	if(root == NULL){
		return 0;
	}else{
		return 1 + max(maxDepth(root->left), maxDepth(root->right));	}
}

// given a bst, return the min value of the tree;

 int minValue(node * root){
 	if(root->left ==NULL){
 		return root->data;
 	}else{
 		return minValue(root->left);
 	}
}

void printTree(node * root){
	// base
	if(root==NULL){
		return;
	}else{
	
		printTree(root->left);
			cout << root->data;
		printTree(root->right);
	}
}

//0return true if there exist a path from root to leaf which sums to the given sum;
bool hasPathSum(node * root, sum){
// base
	if(root == NULL){
		return sum==0;
	}else{

		int subSum = sum - root->data;
		// leaf node
		if(isLeaf(root)) return subSum == 0;
		return hasPathSum(root->left, subSum)
				or
				hasPathSum(root->right, sumSum);
	}
}





// 1,2, 3, 4, .. . n
// return the number of unique bst using n values;
int countTrees(int n){
	// base
	if(n <= 1){
		return 1;
	}else{
		int sum= 0;
		// for each i , 1, ... n
		for(int i = 1; i <= n; i++){
			int l = countTrees(i-1);
			int r= countTrees(n-i);
			sum += l*r;
		}
		return sum;
	}

}
// return true if BST else return false;
bool isBST(node *root){
	if(root==NULL) return true;
	else{
		if(root->left){
			if(root->left->data < root->data)
		}
		return isBST(root->left) and 
				isBST(root->right);
	}
}




// helper to print the paths
void printPathHelper(node * root, int path[], int pathlen){
	// empty tree
	if(root==NULL) return;
	path[pathlen] = root->data;
	pathlen++;
	// if leaf
	if(isLeaf(root)){
		printarray(path, pathlen);
		return;
	}else{
		printPathHelper(root->left, path, pathlen);
		printPathHelper(root->right, path, pathlen);
	}
}
// print all root to leaf path
void printPath(node * root){
	int path[1000];
	int pathlen = 0;
	printPathHelper(root, path, pathlen);
}

// find lca in bst
int lca(node * root, int a, int b){
	if(!root) return -1;
	// if(root->data == a or root->data == b)
	// 	return root->data;
	else{
		// if a and b > root->data
		// go right
		if(a > root->data and b > root->data)
			return lca(root->right, a, b);
		if(a < root->data and b < root->data)
			return lca(root->left, a, b);
		return root->data;
	}

}

int main(){
	node * root = insert(root, 3);
	root = insert(root, 4);
	cout << "lca of 3 and 4 is : " << lca(root, 3, 4);
	cout << endl;
}




















































































































































