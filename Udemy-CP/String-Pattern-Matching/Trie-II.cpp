/*
Author :     Arkajyoti Saha
Problem Link:https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
	unordered_map<char, Node*> children;
	char data;
	bool terminal = false;
	int cnt_end = 0;
	int cnt_pre = 0 ;

	Node(char data){
		this->data = data;
		terminal = false;
	}

};
class Trie{
private:
	Node* root;
public:
    Trie(){
        root = new Node('\0');
    }

    void insert(string &word){ // this acts as a pointer on the string
		Node* node = root;
		for(char ch: word){
			if(node->children.count(ch)){ // if the character of the word is alredy prasent
				node = node->children[ch]; //moving next
			}
			else{
				Node* newNode = new Node(ch); //creating a newNode of ch
				node->children[ch] = newNode; //connecting the node to newNode
				node = newNode;
			}
			node->cnt_pre += 1;
		}
		node->cnt_end += 1;
		node->terminal = true;
	}

    int countWordsEqualTo(string &word){
        Node* node = root;
		for(char ch:word){
			if(node->children.count(ch) == 0){
				return 0;
			}
			node = node->children[ch];
		}
		return node->cnt_end;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
		for(char ch:word){
			if(node->children.count(ch) == 0){
				return 0;
			}
			node = node->children[ch];
		}
		return node->cnt_pre;
    }

    void erase(string &word){
        Node* node = root;
        for(char ch: word){
        	 if(node->children.count(ch)){
        	 	node = node->children[ch];
        	 	node->cnt_pre -= 1;
        	 }
        	 else{
        	 	return;
        	 }
        }
        node->cnt_end -= 1; 
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
	




}