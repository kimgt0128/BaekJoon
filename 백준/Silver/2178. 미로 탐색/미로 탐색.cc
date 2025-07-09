#include<iostream>
#include<queue>
#define F first
#define S second
#define IN(Y, X) Y >= 0 && Y < N && X >= 0 && X < M
using namespace std;
typedef pair<int, int> PII;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int N, M, ans, board[100][100];
bool visit[100][100];
queue<PII> que;

int BFS(int y, int x) {
	visit[y][x] = true;
	que.push({ y, x });

	while (!que.empty()) {
		PII cur = { que.front().F, que.front().S };
		que.pop();
		int cy = cur.F;
		int cx = cur.S;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!visit[ny][nx] && board[ny][nx] && IN(ny, nx)) {
				que.push({ ny, nx });
				visit[ny][nx] = true;
				board[ny][nx] = 1 + board[cy][cx];
				if (ny == N - 1 && nx == M - 1) return board[ny][nx];
			}
		}
	}
}



int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	cout << BFS(0, 0);
	return 0;
}
