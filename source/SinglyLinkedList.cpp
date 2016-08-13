#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* insertEnd(ListNode* root, int val){
	ListNode* temp = new ListNode(val);
	if(root==NULL){
		return temp;
	}
	
	ListNode* cur = root;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cur->next = temp;
	return root;
}

ListNode* insertFront(ListNode* root, int val){
	ListNode* temp = new ListNode(val);
	temp->next = root;
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
		temp->next = root;
		return temp;
	}else{
		ListNode* cur = root;
		ListNode* prev = root;
		int index = 1;
		while(cur!=NULL && index!=pos){
			prev = cur;
			cur = cur->next;
			index++;
		}
		if(index == pos){
			prev->next = temp;
			temp->next = cur;
		}else{
			delete temp;
			cout<<"Position Not Found\n";
		}
		return root;
	}
}

ListNode* deleteWithVal(ListNode* root, int el){
	if(root==NULL){
		cout<<"List Empty\n";
	}else if(root->val==el){
		ListNode* temp = root;
		root=root->next;
		delete temp;
	}else{
		ListNode* cur = root;
		ListNode* prev = root;
		while(cur!=NULL){
			if(cur->val == el){
				break;
			}else{
				prev = cur;
				cur = cur->next;
			}
		}
		
		if(cur!=NULL){
			ListNode* temp = cur;
			prev->next = cur->next;
			delete temp;
		}else{
			cout<<"Element Not Found\n";
		}
	}
	return root;
}

ListNode* deleteAtPos(ListNode* root, int pos){
	if(root==NULL){
		cout<<"List Empty\n";
	}else if(pos==1){
		ListNode* temp = root;
		root = root->next;
		delete temp;
	}else{
		ListNode* cur = root;
		ListNode* prev = root;
		int index = 1;
		while(cur!=NULL && index!=pos){
			prev = cur;
			cur = cur->next;
			index++;
		}
		
		if(index == pos){
			ListNode* temp = cur;
			prev->next = cur->next;
			delete temp;
		}else{
			cout<<"Position Not Found\n";
		}
	}
	return root;
}

void printList(ListNode* root){
	if(root==NULL){
		cout<<"Empty List"<<'\n';
		return;
	}
	while(root->next!=NULL){
		cout<<root->val<<"->";
		root = root->next;
	}
	cout<<root->val<<'\n';
}

bool search(ListNode* root, int el){
	if(root==NULL){
		cout<<"List is empty\n";
	}
	ListNode* cur = root;
	while(root!=NULL){
		if(root->val == el){
			break;
		}
	}
	if(root!=NULL){
		return true;
	}else{
		return false;
	}
}

int main(){
	ListNode* root;
	/*for(int i=0;i<3;i++){
		root = insertEnd(root,i);
	}
	printList(root);
	cout<<"Deleting element 0"<<'\n';
	root = deleteWithVal(root,2);
	printList(root);*/
	
	for(int i=0;i<3;i++){
		root = insertFront(root,i);
	}
	printList(root);
	//cout<<"Inserting .... \n";
	//root = insertAtPosition(root,3,5);
	//printList(root);
	
	cout<<"Deleting ... \n";
	root = deleteAtPos(root,3);
	printList(root);
}