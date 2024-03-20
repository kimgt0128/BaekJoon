#include<iostream>
#include<vector>

using namespace std;

int N, K, cnt;
string str;
vector<int> v;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K >> str;

	for (int i = 0; i < str.size(); i++) {
		int num = str[i] - '0';
		if (cnt == K) v.push_back(num);
		else {
			if (v.empty() || num <= v.back()) v.push_back(num);
			else {
				while (!v.empty() && cnt < K && num > v.back()) {
					v.pop_back();
					cnt++;
				}
				v.push_back(num);
			}
		}
	}
	if (cnt < K) {
		while (cnt < K) {
			v.pop_back();
			cnt++;
		}
	}
	for (int i = 0; i < v.size(); i++) cout << v[i];
	return 0;
}