#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

string str;
string sta;
string cmp;

int main(void) {
	FAST_IO;

	cin >> str;
	cin >> cmp;
	for (int i = 0; i < str.size(); i++) {
		sta.push_back(str[i]);
		if (sta.size() < cmp.size()) continue;
		
		if (sta.substr(sta.size() - cmp.size(), cmp.size()) == cmp) {
			for (int j = 0; j < cmp.size(); j++) {
				sta.pop_back();
			}
		}
	}

	if (sta.empty()) cout << "FRULA\n";
	else cout << sta;
}