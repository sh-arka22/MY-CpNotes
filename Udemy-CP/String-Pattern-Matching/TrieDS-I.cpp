/*
Author :     Arkajyoti Saha
Problem Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
	unordered_map<char, Node*> children;
	char data;
	bool terminal = false;

	Node(char data){
		this->data = data;
		terminal = false;
	}

};
class Trie{
private: 
	Node* root;
	int count;
public:
	Trie(){
		root = new Node('\0');
		count = 0;
	}
	void insert(string word){ // this acts as a pointer on the string
		Node* node = root;
		for(int i=0; i<word.size(); i++){
			char ch = word[i];
			if(node->children.count(ch)){ // if the character of the word is alredy prasent
				node = node->children[ch]; //moving next
			}
			else{
				Node* newNode = new Node(ch); //creating a newNode of ch
				node->children[ch] = newNode; //connecting the node to newNode
				node = newNode;
			}
		}
		node->terminal = true;
	}
	bool find(string word){
		Node* node = root;
		for(char ch:word){
			if(node->children.count(ch) == 0){
				return false;
			}
			node = node->children[ch];
		}
		return node->terminal;
	}
	bool startWith(string word){ // this returns true if there is a word that forms a prifix of another string
		Node* node = root;
		for(char ch:word){
			if(node->children.count(ch) == 0){
				return false;
			}
			node = node->children[ch];
		}
		return true;
	}
};

void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int32_t main() {
	file_i_o();
	Trie trie;
	vector<string>words = {"a", "hello", "helloyee", "welcome", "comein"};

	for(auto s:words){
		trie.insert(s);
	}
	string w;
	cin>>w;

	if(trie.find(w)){
		cout<<"prasent";
	}
	else 
		cout<<"not prasent";

}