/**********************************************************/
/*  File name: 2171.cpp                                   */
/*                                                        */
/*  Author: Lamzin Oleh                                   */
/*          olehtomas@gmail.com                           */
/*                                                        */
/*  Time: 21:14:02 04/28/15                               */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < vector<int> > pi;
vector <string> ss;
string s;
int n;

vector<int> prefix_function(string s){
	int n = s.length();
	vector <int> pi(n);
	for (int i = 1; i < n; i++){
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}

	return pi;
}

bool check_once(string s){
	for (int i = 0; i < pi.size(); i++){

		int cur = 0;
		for(int ii = 0; ii < s.length(); ii++){
			while(cur > 0 && ss[i][cur] != s[ii]) cur = pi[i][cur - 1];
			if (ss[i][cur] == s[ii]) cur++;

			if (cur == ss[i].length()) return true;
		}
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);

	cin >> n;
	getline(cin, s);
	pi.resize(n);
	ss.resize(n);

	for (int i = 0; i < n; i++){
		getline(cin, ss[i]);
		pi[i] = prefix_function(ss[i]);
	}

	while(cin){
		getline(cin, s);
		if (cin && check_once(s)) cout << s << endl;
	}
}
