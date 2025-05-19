#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 100000
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

stack<char> sta;
bool tag;

void printStack(bool tag) {
	vector<char> word;
	while (!sta.empty()) {
		word.push_back(sta.top());
		sta.pop();
	}
	if (tag) reverse(word.begin(), word.end());
	for (auto c : word) cout << c;
	word.clear();
}

int main(void) {
	FAST_IO;
	string line;
	getline(cin, line);

	for (int i = 0; i <= line.size(); i++) {
		char cur = line[i];
		if (cur == '<') {
			printStack(tag);
			sta.push(cur);
			tag = true;
		}
		else if (cur == '>') {
			sta.push(cur);
			printStack(tag);
			tag = false;
		}
		else if (cur == ' ' || cur == NULL) {
			printStack(tag);
			cout << ' ';
		}
		else {
			sta.push(cur);
		}
	}
}