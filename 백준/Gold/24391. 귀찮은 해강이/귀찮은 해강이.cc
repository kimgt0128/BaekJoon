#include<iostream>

using namespace std;

int par[100001];
int lec[100001];
int ans;
int Find(int x) {
	if (par[x] == x) return x;
	else return par[x] = Find(par[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) par[y] = par[x];
	else  par[x] = y;
}

bool IsUnion(int x, int y) {
	if (Find(x) == Find(y)) return true;
	else return false;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	while (m--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) cin >> lec[i];

	int comp = lec[1];
	for (int i = 2; i <= n; i++) {
		if (!IsUnion(lec[i], comp)) {
			comp = lec[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}