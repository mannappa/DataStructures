#include <iostream>
#include <string>
using namespace std;

class TrieNode{
	int isLeaf;
	//Assuming all the characters of lower case, a letter can
	//have maximum of 26 possibility of next letter in a word.
	TrieNode* children[26];
	//Above is the array of pointers
	int prefixCount;
public:
	void insert(const string& word);
	TrieNode* getNode();
	bool search(const string& word);
	void printAllWithPrefix(const string& prefix);
	void print(const string buf,const string& prefix);
	void test();
};

TrieNode* TrieNode::getNode(){
	TrieNode* temp = new TrieNode();
	temp->isLeaf = false;
	temp->prefixCount = 0;
	for(int i=0;i<26;i++){
		temp->children[i]=NULL;
	}
	return temp;
}

void TrieNode::insert(const string& word){
	//cout<<"Inserting "<<word<<" ..\n";
	TrieNode* current = this;
	for(int i=0;i<word.size();i++){
		if(current->children[word[i]-'a']==NULL){
			current->children[word[i]-'a'] = getNode();
			current->prefixCount++;
		}
		current = current->children[word[i]-'a'];
	}
	current->isLeaf = true;
}

bool TrieNode::search(const string& word){
	TrieNode* current = this;
	for(int i=0;i<word.size();i++){
		if(current->children[word[i]-'a']==NULL){
			return false;
		}
		current = current->children[word[i]-'a'];
	}
	return current->isLeaf;
}

void TrieNode::printAllWithPrefix(const string& prefix){
	TrieNode* current = this;
	//cout<<"1...\n";
	for(int i=0;i<prefix.size();i++){
		if(current->children[prefix[i]-'a']==NULL){
			return;
		}
		current = current->children[prefix[i]-'a'];
	}
	string buf;
	//cout<<"Calling print...\n";
	current->print(buf,prefix);
}

void TrieNode::print(const string buf,const string& prefix){
	//cout<<"Entered print\n";
	if(this->prefixCount==0){
		cout<<prefix+buf<<"\n";
		return;
	}else{
		if(this->isLeaf){
			cout<<prefix+buf<<"\n";
		}
		for(int i=0;i<(sizeof(this->children)/sizeof(TrieNode*));i++){
			if(children[i]!=NULL){
				children[i]->print(buf+char('a'+i),prefix);
			}
		}
	}
}
	
void TrieNode::test(){
	for(int i=0;i<26;i++){
		if(this->children[i]!=NULL){
			cout<<char('a'+i)<<"\n";
		}
	}
}

int main(){
	TrieNode* root = root->getNode();
	int size = 7;
	string keys[size] = {"cat","cats","meow","bow","carpet","meal","good"};
	for(int i=0;i<size;i++){
		root->insert(keys[i]);
	}

	root->test();
	cout<<"Searching meow...\n";
	
	/*if(root->search("meow")){
		cout<<"Found Meow\n";
	}else{
		cout<<"No meow found\n";
	}*/
	root->test();
	root==NULL ? cout<<">>>>>>>>True":cout<<">>>>>>>False";
	root->printAllWithPrefix("cat");
	root->printAllWithPrefix("me");
	return 0;
}
