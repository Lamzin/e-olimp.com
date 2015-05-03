/**********************************************************/
/*  File name: 2891.cpp                                   */
/*                                                        */
/*  Author: Lamzin Oleh                                   */
/*          olehtomas@gmail.com                           */
/*                                                        */
/*  Time: 04:25:45 05/03/15                               */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

#define FILE_IO
#define ALPHABET 28
#define SIZE 20000
#define what_is(x) cout << #x << " = " << x << endl

#ifdef FILE_IO
#include <fstream>
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#define cin in
#define cout out
#endif

struct item
{
	int next[ALPHABET];
	int leaf;

	item(){
		for (int i = 0; i<ALPHABET; i++) next[i] = -1;
		leaf = 0;
	}
};

vector<item> trie(1);
int new_ch[256];
int prefix[SIZE];

void make_new_char(){
	for (int i = 'a'; i<='z'; i++) new_ch[i] = i - 'a';
	for (int i = 'A'; i<='Z'; i++) new_ch[i] = i - 'A';
	new_ch[39] = 26;
	new_ch[96] = 27;
}

void add(string &s){
	int v = 0;
	item tmp;

	for (int i = 0; i < s.length(); i++){
		int ch = new_ch[s[i]];
		if (trie[v].next[ch] == -1){
			trie[v].next[ch] = trie.size();
			trie.push_back(tmp);
		}
		v = trie[v].next[ch];
	}
	trie[v].leaf = 1;
}

int main(){
	make_new_char();
	int n;
	string s;

	cin >> n;
	getline(cin, s);
	
	for (int i = 0; i < n; i++){
		getline(cin, s);
		add(s);
	}

	getline(cin, s);
	
	for(int i = 0, v = 0; i < s.length() && v != -1; i++){
		v = trie[v].next[new_ch[s[i]]];
		if (v > 0 && trie[v].leaf) prefix[i] = 1;
	}

	for (int i = 0; i < s.length(); i++){
		if (prefix[i]){
			for(int j = i + 1, v = 0; v != -1 && j < s.length(); j++){
				v = trie[v].next[new_ch[s[j]]];
				if (v > 0 && trie[v].leaf == 1) prefix[j] = 1;
			}
		}
	}

	cout << ((prefix[s.length() - 1]) ? "YES" : "NO") << endl;
}
