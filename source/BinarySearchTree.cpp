#include <iostream>
#include <iomanip>
using namespace std;

struct BSTNode{
	int val;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int data):val(data),left(NULL),right(NULL){}
};

BSTNode* insert(BSTNode* root, int el){
	if(root==NULL){
		BSTNode* temp = new BSTNode(el);
		return temp;
	}else if(root->val > el){
		root->left = insert(root->left,el);
	}else{
		root->right = insert(root->right,el);
	}
	return root;
}

void inorder(BSTNode* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->val<<"->";
	inorder(root->right);
}

void fancyPrint(BSTNode* root, int level){
	if (root != NULL)
    {
        fancyPrint(root->right, level + 4);
        //if (level > 0)
        cout << setw(level) << " ";
        cout << root->val << endl;
        fancyPrint(root->left, level + 4);
    }
}

BSTNode* minRight(BSTNode* root){
	if(root->left == NULL){
		return root;
	}else{
		return minRight(root->left);
	}
}

BSTNode* remove(BSTNode* root, int el){
	if(root==NULL){
		return root;
	}
	
	if(root->val == el){
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}else if(root->left == NULL){
			BSTNode* temp = root->right;
			root->val = temp->val;
			delete temp;
			temp = NULL;
		}else if(root->right == NULL){
			BSTNode* temp = root->left;
			root->val = temp->val;
			delete temp;
			temp = NULL;
		}else{
			BSTNode* minr = minRight(root->right);
			root->val = minr->val;
			root->right = remove(root->right,minr->val);
		}
	}else if(root->val < el){
		root->right = remove(root->right,el);
	}else{
		root->left = remove(root->left,el);
	}
	return root;
}

int main(){
	BSTNode* root=NULL;
	root = insert(root,8);
	root = insert(root,5);
	root = insert(root,4);
	root = insert(root,6);
	root = insert(root,11);
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,14);
	inorder(root);
	cout<<'\n';
	fancyPrint(root,0);
	remove(root,90);
	fancyPrint(root,0);
	return 0;
}