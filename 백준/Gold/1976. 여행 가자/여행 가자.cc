#include<iostream>

using namespace std;
int N, M;
int par[201];
int ran[201];
bool flag = true;
int root;

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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bool link;
			cin >> link;
			if(link) Rank(i, j);
		}
	}
	for (int i = 1; i <= M; i++) {
		int node;
		cin >> node;
		if (i == 1) {
			root = Find(node);
			continue;
		}

		if (root != Find(node)) {
			flag = false;
			break;
		}
		
	}
	if (flag) cout << "YES";
	else cout << "NO";
	return 0;
}
