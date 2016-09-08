#include <iostream>
#include <string>
using namespace std;

struct TrieNode{
	int isLeaf;
	//Assuming all the characters of lower case, a letter can
	//have maximum of 26 possibility of next letter in a word.
	TrieNode* children[26];
	//Above is the array of pointers
	int prefixCount;
/*public:
	void insert(const string& word);
	TrieNode* getNode();
	bool search(const string& word);
	void printAllWithPrefix(const string& prefix);
	void print(const string buf,const string& prefix);
	void test();*/
};

TrieNode* getNode(){
	TrieNode* temp = new TrieNode();
	temp->isLeaf = false;
	temp->prefixCount = 0;
	for(int i=0;i<26;i++){
		temp->children[i]=NULL;
	}
	return temp;
}

void insert(TrieNode* root, const string& word){
	//cout<<"Inserting "<<word<<" ..\n";
	TrieNode* current = root;
	for(int i=0;i<word.size();i++){
		if(current->children[word[i]-'a']==NULL){
			current->children[word[i]-'a'] = getNode();
			current->prefixCount++;
		}
		current = current->children[word[i]-'a'];
	}
	current->isLeaf = true;
}

bool search(TrieNode* root, const string& word){
	TrieNode* current = root;
	for(int i=0;i<word.size();i++){
		if(current->children[word[i]-'a']==NULL){
			return false;
		}
		current = current->children[word[i]-'a'];
	}
	return current->isLeaf;
}

void print(TrieNode* root,const string buf,const string& prefix){
	//cout<<"Entered print\n";
	if(root->prefixCount==0){
		cout<<prefix+buf<<"\n";
		return;
	}else{
		if(root->isLeaf){
			cout<<prefix+buf<<"\n";
		}
		for(int i=0;i<(sizeof(root->children)/sizeof(TrieNode*));i++){
			if(root->children[i]!=NULL){
				print(root->children[i],buf+char('a'+i),prefix);
			}
		}
	}
}

void printAllWithPrefix(TrieNode* root, const string& prefix){
        TrieNode* current = root;
        //cout<<"1...\n";
        for(int i=0;i<prefix.size();i++){
                if(current->children[prefix[i]-'a']==NULL){
                        return;
                }
                current = current->children[prefix[i]-'a'];
        }
        string buf;
        //cout<<"Calling print...\n";
        print(current,buf,prefix);
}

	
void test(TrieNode* root){
	for(int i=0;i<26;i++){
		if(root->children[i]!=NULL){
			cout<<char('a'+i)<<"\n";
		}
	}
}

int main(){
	TrieNode* root = getNode();
	int size = 7;
	string keys[size] = {"cat","cats","meow","bow","carpet","meal","good"};
	for(int i=0;i<size;i++){
		insert(root,keys[i]);
	}

	test(root);
	cout<<"Searching meow...\n";
	
	/*if(root->search("meow")){
		cout<<"Found Meow\n";
	}else{
		cout<<"No meow found\n";
	}*/
	test(root);
	root==NULL ? cout<<">>>>>>>>True":cout<<">>>>>>>False";
	printAllWithPrefix(root,"cat");
	printAllWithPrefix(root,"me");
	return 0;
}
