#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

string str;

int main(void) {
	
	cin >> str;

	int st = 0;
	int en = str.size() - 1;
	bool flag = false;
	char cmp = str[0];
	while (st <= en) {
		if (str[st] == str[en]) {
			if (str[st] != cmp) flag = true;
			st++, en--;
		}
		else break;
	}

	if (st > en) {
		if (!flag) cout << -1;
		else cout << str.size() - 1;
	}
	else cout << str.size();

}