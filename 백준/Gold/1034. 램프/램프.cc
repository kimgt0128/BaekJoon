#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


int n, m, k, ans;
vector<string> lamps;
map<string, int> forms;

int main(void) {
	FAST_IO;

	cin >> n >> m;

	lamps = vector<string>(n, "");

	for (int i = 0; i < n; i++) {
		cin >> lamps[i];
		forms[lamps[i]]++;
	}
	cin >> k;


	for (auto e : forms) {
		string f = e.first;
		int zero_cnt = count(f.begin(), f.end(), '0');
		if (zero_cnt > k) continue;
	
		if ((k - zero_cnt) % 2 == 1) continue;
		ans = max(ans, e.second);
	}

	cout << ans;

}