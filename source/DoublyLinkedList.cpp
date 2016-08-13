#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* left;
	ListNode* right;
	ListNode(int x):val(x),left(NULL),right(NULL){}
};

ListNode* insertEnd(ListNode* root, int val){
	ListNode* temp = new ListNode(val);
	if(root==NULL){
		return temp;
	}
	
	ListNode* cur = root;
	while(cur->right!=NULL){
		cur = cur->right;
	}
	cur->right = temp;
	temp->left = cur;
	return root;
}

ListNode* insertFront(ListNode* root, int val){
	ListNode* temp = new ListNode(val);
	temp->right = root;
	root->left = temp;
	return temp;
}

ListNode* insertAtPosition(ListNode* root, int val, int pos){
	ListNode* temp = new ListNode(val);
	if(root==NULL && pos==1){
		return temp;
	}else if(root==NULL && pos!=1){
		cout<<"Position Not Found\n";
		delete temp;
		return root;
	}else if(root!=NULL && pos==1){
		temp->right = root;
		root->left = temp;
		return temp;
	}else{
		ListNode* cur = root;
		ListNode* prev = root;
		int index = 1;
		while(cur!=NULL && index!=pos){
			prev = cur;
			cur = cur->right;
			index++;
		}
		if(index == pos && cur!=NULL){
			prev->right = temp;
			temp->left = prev;
			temp->right = cur;
			cur->left = temp;
		}else if(index==pos){
			prev->right = temp;
			temp->left = prev;
		}else{
			delete temp;
			cout<<"Position Not Found\n";
		}
		return root;
	}
}

ListNode* deleteNodeValue(ListNode* root,int el){
	if(root==NULL){
		cout<<"Empty List"<<'\n';
	}else if(root->val == el){
		ListNode* temp = root;
		root = root->right;
		root->left = NULL;
		delete temp;
	}else{
		ListNode* cur = root;
		while(cur!=NULL){
			if(cur->val == el){
				break;
			}
			cur = cur->right;
		}
		if(cur->val == el && cur->right!=NULL){
			ListNode* temp = cur;
			cur->left->right = cur->right;
			cur->right->left = cur->left;
			delete temp;
		}else if(cur->val == el){
			ListNode* temp = cur;
			cur->left->right = cur->right;
			delete temp;
		}else{
			cout<<"Element Not Foudn in the List\n";
		}
	}
	return root;
}

void printList(ListNode* root){
	if(root==NULL){
		cout<<"Empty List"<<'\n';
		return;
	}
	while(root->right!=NULL){
		cout<<root->val<<"->";
		root = root->right;
	}
	cout<<root->val<<'\n';
}


int main(){
	ListNode* root;
	for(int i=0;i<3;i++){
		root = insertEnd(root,i);
	}
	printList(root);
	/*cout<<"Deleting element 0"<<'\n';
	root = deleteWithVal(root,2);
	printList(root);
	
	for(int i=0;i<3;i++){
		root = insertFront(root,i);
	}
	printList(root);
	cout<<"Inserting .... \n";
	root = insertAtPosition(root,3,5);
	printList(root);
	
	cout<<"Deleting ... \n";
	root = deleteAtPos(root,3);
	printList(root);*/
	
	root = insertAtPosition(root,4,4);
	printList(root);
	root = deleteNodeValue(root,1);
	printList(root);
}