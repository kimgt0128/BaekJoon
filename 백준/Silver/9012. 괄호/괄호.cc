#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> sta;
string str;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> str;
		int len = str.length();
		int index = 0;
		while (index < len) {
			if (sta.empty()) {
				sta.push(str[index++]);
				continue;
			}
			if (str[index] == ')' && sta.top() == '(') sta.pop();
			else sta.push(str[index]);
			index++;
		}
		if (sta.empty()) cout << "YES\n";
		else cout << "NO\n";
		while (!sta.empty()) {
			sta.pop();
		}
	}
	return 0;
}
