#include<iostream>

using namespace std;

int par[1000001];

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

void IsUnion(int x, int y) {
	if (Find(x) == Find(y)) cout << "YES\n";
	else cout << "NO\n";
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	while (m--) {
		int order, a, b;
		cin >> order >> a >> b;
		if (!order) Union(a, b);
		else IsUnion(a, b);
	}

	return 0;
}