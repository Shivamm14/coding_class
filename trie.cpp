#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
	string name;
	TrieNode *next[10];
};
// asuu
void insert(TrieNode* root, string pin, string name){

	// for each char in pin
	// insert
	TrieNode *thumb = root;
	for(auto x : pin){
		if(thumb->next[x-'0']==NULL){
			thumb->next[x-'0'] = new TrieNode;
		}
		thumb = thumb->next[x-'0'];
	}
	thumb->name = name;
}
string search(TrieNode * root, string pin){
	TrieNode *thumb = root;
	// for each char in pin
	for(auto x : pin){
		if(thumb->next[x-'0'] == NULL) 
			return "Not Found!";
		thumb = thumb->next[x-'0'];
	}
	return thumb->name;
}

// find the shortest prefix of s 
//which is not a prefix of any string 
string shortest_prefix(vector<string> words, string s){
	// for each prefix of s
	// 	check if that prefix exist in any word of words
	string prefix;
	for(auto x : s){
		prefix.push_back(x);
		bool found = false;
		// search this prefix with each word in words 
		for(auto word : words){
			// check if prefix exist in word 
				string prefix_word = word.substr(0, prefix.length());	
				if(prefix == prefix_word){
					found =true;
					break;
				}
		}
		if(!found) return prefix; 
	}
	return "";

}




int main(){
	vector<string> words = {"abc", "abcd", "abcc", "be"};	
	cout << shortest_prefix(words, "abce") << endl;
	cout << shortest_prefix(words, "bcd") << endl;
	cout << shortest_prefix(words, "ae") << endl;

	// TrieNode * root = new TrieNode;
	// insert(root, "9312", "Anmol");
	// insert(root, "9356", "Ayush");
	// insert(root, "1234", "Abhishek");
	// cout <<  search(root, "9312") << endl;
	// cout <<  search(root, "1234") << endl;
	// cout << search (root, "7114") << endl;
	// insert(root, "7114", "Bidu");
	// cout << search(root, "7114") << endl;
	// cout << search(root, "711") << endl;
}
