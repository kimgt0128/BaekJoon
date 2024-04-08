#include<iostream>
#include<vector>
using namespace std;

int N, M, T, ans;
//루트 노드가 0이라면 진실, 아니라면 거짓
int par[51];
vector<vector<int>> party(51);

int Find(int x) {
	return x == par[x] ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	par[y] = x;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> T;

	//루트 노드 초기화
	for (int i = 1; i <= N; i++) par[i] = i;

	while (T--) {
		int x;
		cin >> x;
		Union(0, x);
	}
	for (int i = 1; i <= M; i++) {
		int n, t;//파티원 수, 파티에서 말한 진실/거짓여부
		t = -1;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			party[i].push_back(x);//파티장 기록 -> 이후 정답 찾기
			if (!Find(x)) t = 0; //파티원중 한명이라도 진실을 아는 경우 t = 0
		}
		if (t != 0) t = Find(party[i][0]);
		for (int j = 0; j < n; j++) Union(t, party[i][j]);
	}
	//정답 찾기
	for (int i = 1; i <= M; i++) {
		int x = party[i][0];
		if (Find(x)) ans++;
	}
	cout << ans;
}