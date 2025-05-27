#include<iostream>
#include<algorithm>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


vector<string> words;
string ans;

int main(void) {
	FAST_IO;
	string str;
	cin >> str;

	bool is_snake = false;
	if (str.find('_') != string::npos) is_snake = true;
	
	int idx = 0;
	int st = 0;
	for (idx = 0; idx < str.size(); idx++) {
		char cur = str[idx];
		if (cur == '_') {
			if (st == idx) continue;
			string temp = str.substr(st, idx-st);
			words.push_back(temp);
			st = idx + 1;
		}
		if (isupper(cur)) {
			words.push_back(str.substr(st, idx-st));
			st = idx;
		}
	}
	words.push_back(str.substr(st, idx));


	if (isupper(str[0]) 
		or str[0] == '_'
		or str[str.size()-1] == '_'
		or (is_snake && count(str.begin(), str.end(), '_') != words.size() - 1)) cout << "Error!";
	else {


		for (int i = 0; i < words.size(); i++) {
			string s = words[i];
			if (i == 0) {
				ans += s;
				continue;
			}
			if (is_snake) {
				s[0] = toupper(s[0]);
			}
			else {
				s[0] = tolower(s[0]);
				s = '_' + s;
			}
			ans += s;
		}


	}

	cout << ans;

}