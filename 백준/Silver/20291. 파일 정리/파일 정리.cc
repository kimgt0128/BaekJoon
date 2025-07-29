#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


int n;
map<string, int> ans;


int main(void) {
	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		replace(str.begin(), str.end(), '.', ' ');


		istringstream iss(str);

		string name, form;
		iss >> name >> form;

		ans[form]++;

	}

	for (pair<string, int> pair : ans) {
		cout << pair.first << " " << pair.second << "\n";
	}
	return 0;
}

