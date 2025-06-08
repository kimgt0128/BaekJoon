#include<iostream>
#include<algorithm>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y>=0 and Y<N and X >= 0 and X < N)
#define F first
#define S second
#define INF 0x7fffffff
using namespace std;
typedef pair<int, int> PII;

int N;
int board[1000][1000];
int ans[1001][1001];

int dir_y[4] = { 1, 0, -1, 0 };
int dir_x[4] = { 0, 1, 0, -1 };

void travel(int y, int x) {
	queue<PII> que;
	ans[y][x] = board[y][x];
	que.push({ y, x });
	while (!que.empty()) {
		PII cur = que.front();
		que.pop();
		
		for (int i = 0; i < 4; i++) {
			PII nxt = { cur.F + dir_y[i], cur.S + dir_x[i] };
			if (IN(nxt.F, nxt.S) and ans[nxt.F][nxt.S] > ans[cur.F][cur.S] + board[nxt.F][nxt.S]) {
				ans[nxt.F][nxt.S] = ans[cur.F][cur.S] + board[nxt.F][nxt.S];
				que.push({ nxt.F, nxt.S });
			}
		}
	}
}

int main(void) {
	FAST_IO;
	int cnt = 0;
	while (true) {
		cin >> N;
		if (!N) break;
		cnt++;
		for (int i = 0; i < N; i++) fill(ans[i], ans[i] + N, INF); // 최초 방문시에도 최소를 보장하하도록 무한으로 초기화!
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> board[i][j];
		}
		travel(0, 0);
		cout << "Problem " << cnt << ": " << ans[N-1][N-1] << "\n";
	}
	return 0;

}