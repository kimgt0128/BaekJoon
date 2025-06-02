#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


string str;
string sta;

int main(void) {
	FAST_IO;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		sta.push_back(str[i]);
		if(sta.size() >= 4 && sta.substr(sta.size() - 4, 4) == "PPAP") {
			for (int j = 0; j < 3; j++) {
				sta.pop_back();
			}
		}
	}
	if (sta.size() == 1 && sta.back() == 'P') cout << "PPAP";
	else cout << "NP";
}
