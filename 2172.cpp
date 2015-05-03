/**********************************************************/
/*  File name: 2172.cpp                                   */
/*                                                        */
/*  Author: Lamzin Oleh                                   */
/*          olehtomas@gmail.com                           */
/*                                                        */
/*  Time: 03:44:53 05/03/15                               */
/*                                                        */
/**********************************************************/

/*using algorithm Aho-Corasick*/

/**********************************************************/
/*  File name: Aho–Corasick.cpp                           */
/*                                                        */
/*  Author: Lamzin Oleh                                   */
/*          olehtomas@gmail.com                           */
/*                                                        */
/*  Time: 23:47:11 05/02/15                               */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ALPHABET 128
#define what_is(x) cerr << #x << " = " << (x) << endl

#define FFFILE
#ifdef FFFILE
#include <fstream>
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif


class trie{
public:
	struct item{
		//int next[ALPHABET], go[ALPHABET];
		map <int, int> next, go;
		int leaf, dictIndex;
		int parent; char parentch;
		int link;
		int nextTerminal;
		item();
	};

	vector<item> vect;
	vector<string> dict;
	vector<int> curTerminal;

	trie();
	void add(string &s);

	int go(int v, char c);
	int get_link(int v);

	int nextTerminal(int v);
	void makeTerminal(int v);
} Trie;

int main(){
	int n, v = 0;
	string s, text;
	
	cin >> n;
	getline(cin, s);

	for(int i = 0; i < n; i++){
		getline(cin, s);
		Trie.add(s);
	}

	while(cin){
		getline(cin, text);
		if (cin){
			v = 0;
			for (int i = 0; i < text.length(); i++){
				v = Trie.go(v, text[i]);
				Trie.makeTerminal(v);
				if (Trie.curTerminal.size())
				{
					cout << text << endl;
					break;
				}
			}
		}
	}

	return 0;
}

trie::item::item(){
	//for (int i = 0; i<ALPHABET; i++) next[i] = go[i] = -1;
	leaf = 0;
	dictIndex = nextTerminal = parent = link = -1;
}

trie::trie(){
	vect.push_back(item());
}

void trie::add(string &s){
	int v = 0, sz;
	item temp;

	for (int i = 0; i < s.length(); i++){
		int ch = s[i];
		if (vect[v].next.find(ch) == vect[v].next.end()){
			vect[v].next[ch] = sz = vect.size();
			vect.push_back(temp);
			vect[sz].link = -1;
			vect[sz].parent = v;
			vect[sz].parentch = ch;
		}
		v = vect[v].next[ch];
	}
	vect[v].leaf = 1;
	vect[v].dictIndex = dict.size();
	dict.push_back(s);
}

int trie::get_link(int v){
	if (vect[v].link == -1){
		if (v == 0 || vect[v].parent == 0) vect[v].link = 0;
		else vect[v].link = go(get_link(vect[v].parent), vect[v].parentch);
	}
	return vect[v].link;
}

int trie::go(int v, char ch){
	if (vect[v].go.find(ch) == vect[v].go.end()){
		if (vect[v].next.find(ch) != vect[v].next.end()) vect[v].go[ch] = vect[v].next[ch];
		else vect[v].go[ch] = (!v) ? 0 : go(get_link(v), ch);
	}
	return vect[v].go[ch];
}

int trie::nextTerminal(int v){
	if (vect[v].nextTerminal == -1){
		int vnew = get_link(v);
		while(vnew && !vect[vnew].leaf){
			vnew = get_link(vnew);
		}
		vect[v].nextTerminal = vnew;
	}
	return vect[v].nextTerminal;
}

void trie::makeTerminal(int v){
	curTerminal.clear();
	if (vect[v].leaf) curTerminal.push_back(vect[v].dictIndex);
	int vnew = nextTerminal(v);
	while(vnew){
		curTerminal.push_back(vect[vnew].dictIndex);
		vnew = nextTerminal(vnew);
	}
}
