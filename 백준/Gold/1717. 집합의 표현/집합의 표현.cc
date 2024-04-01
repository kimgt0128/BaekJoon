#include<iostream>

using namespace std;
int N, M;
int par[1000001];
int ran[1000001];

int Find(int x) {
	return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
	if (Find(x) == x) par[y] = x;
	else par[y] = Find(x);
}

void Rank(int x, int y) {
	x = Find(x), y = Find(y);
	if (ran[x] < ran[y]) {
		Union(y, x);
		ran[y] += ran[x];
	}
	else {
		Union(x, y);
		ran[x] = y;
	}
	
}

bool isUnion(int x, int y) {
	if (Find(x) == Find(y)) return true;
	else return false;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i,ran[i]++;
	while (M--) {
		int order;
		cin >> order;
		int a, b;
		cin >> a >> b;
		if (!order) {
			Rank(a, b);
		}
		else {
			if (isUnion(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}




	
	return 0;
}
