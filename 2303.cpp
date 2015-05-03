/**********************************************************/
/*  File name: 2303.cpp                                   */
/*                                                        */
/*  Author: Lamzin Oleh                                   */
/*          olehtomas@gmail.com                           */
/*                                                        */
/*  Time: 12:04:30 04/29/15                               */
/*                                                        */
/**********************************************************/


#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

#define ALPHABET 10
#define what_is(x) cerr << #x << " " << (x) << endl; 

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);
#define cin in
#define cout out

struct node{
	int next[ALPHABET];
	int leaf;
	node(){
		for (int i = 0; i < ALPHABET; i++) next[i] = -1;
		leaf = 0;
	}
};

vector <node> trie(1);
int n, test, call;
string s;

void add_to_trie(string &s){
	int curv = 0, add_new = 0;
	for (int i = 0; i<s.length(); i++){
		int ch = s[i] - '0';
		if (trie[curv].next[ch] == -1){
			trie[curv].next[ch] = trie.size();
			trie.push_back(node());
			add_new = 1;
		}
		curv = trie[curv].next[ch];
		if (trie[curv].leaf == 1){ //some string is s presix
			call = 0;
			return;
		}
	}
	trie[curv].leaf = 1;
	if (!add_new) call = 0; // s is prefix some string!
}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin >> test;

	while(test--){
		cin >> n;
		getline(cin, s);
		trie.clear();
		trie.push_back(node());
		call = 1;

		for (int i = 0; i < n; i++){
			getline(cin, s);
			if (call) add_to_trie(s);
		}

		cout << ((call) ? "YES\n" : "NO\n");
	}
}
