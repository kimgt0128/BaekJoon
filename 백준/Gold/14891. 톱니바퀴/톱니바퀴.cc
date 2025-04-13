#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

vector<deque<int>> cogs(4);

int k;
int ans = 0;


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	



	for (int i = 0; i < 4; i++) {
			string inp;
			cin >> inp;
			for (int j = 0; j < inp.size(); j++) {
				
			cogs[i].push_back(inp[j] - '0');
		}
	}
	cin >> k;

	

	while (k--) {
		int num;
		int dir;
		cin >> num >> dir;

		int cur = num - 1;

		int rot[4] = { 0, 0, 0, 0 };

		rot[cur] = dir;

		while (cur < 3) {
			int nxt = cur + 1;
			if (cogs[cur][2] != cogs[nxt][6]) {
				rot[nxt] = rot[cur] * -1;
			}
			cur++;
		}
		while (cur > 0) {
			int pre = cur - 1;
			if (cogs[cur][6] != cogs[pre][2]) {
				rot[pre] = rot[cur] * -1;
			}
			cur--;
		}

		for (int i = 0; i < 4; i++) {
			if (rot[i] == 1) rotate(cogs[i].begin(), cogs[i].end() - 1, cogs[i].end());
			if(rot[i] == -1) rotate(cogs[i].begin(), cogs[i].begin() + 1, cogs[i].end());
		}





	}
	for (int i = 0; i < 4; i++) {
		if (cogs[i].front() == 1) ans += (1 << i);
	}
	cout << ans;



}