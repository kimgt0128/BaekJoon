#include<iostream>
#include<algorithm>
#include<cstring>
#define F first
#define S second

using namespace std;
int t, n, m;
int cnt[505]; // i번째 팀보다 높은 등수의 팀 개수
int last_rank[505]; // i번째 팀의 순서
pair<int, int> tmp[505]; // 최종 순서

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {

		cin >> n;
		memset(cnt, 0, sizeof(int) * n);
		memset(last_rank, 0, sizeof(int) * n);
		fill(tmp, tmp + n, make_pair(0, 0));
		for (int i = 0; i < n; i++) {
			int team;
			cin >> team;
			last_rank[team] = i + 1;
			cnt[team] = i;
		}
		cin >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			if (last_rank[a] < last_rank[b]) {
				cnt[a]++;
				cnt[b]--;
			}
			else {
				cnt[a]--;
				cnt[b]++;
			}
		}
		for (int i = 1; i < n+1; i++) tmp[i-1] = make_pair(cnt[i], i);
		sort(tmp, tmp + n);
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (tmp[i].F != i) {
				cout << "IMPOSSIBLE\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;
		for (int i = 0; i < n; i++) cout << tmp[i].S << " ";
		cout << '\n';

	}

}