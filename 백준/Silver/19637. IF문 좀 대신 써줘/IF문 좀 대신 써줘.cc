#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;

vector<string> style;
vector<int> standard;

int ch[1000001];


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	style = vector<string>(n);
	standard = vector<int>(n);

	for (int i = 0; i < n; i++) {
		string sty;
		int sta;
		cin >> sty >> sta;
		style[i] = sty;
		standard[i] = sta;
	}

	for (int i = 0; i < m; i++) {
		cin >> ch[i];

		auto it = lower_bound(standard.begin(), standard.end(), ch[i]);
		cout << style[it - standard.begin()] << "\n";
	}
	return 0;
}