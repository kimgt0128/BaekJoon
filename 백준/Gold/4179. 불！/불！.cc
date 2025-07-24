#include<iostream>
#include<queue>
#define IN(Y, X) (Y >= 0 && Y < R && X >= 0 && X < C)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int R, C, ans;
vector<string> board;
vector<vector<int>> man_visit;
vector<vector<int>> fire_visit;

queue<pair<int, int>> fire_que;
queue<pair<int, int>> man_que;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void fire_spread() {

	while (!fire_que.empty()) {
		pair<int, int> cur = fire_que.front();
		fire_que.pop();
		int cy = cur.first;
		int cx = cur.second;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (IN(ny, nx) && board[ny][nx] != '#' && fire_visit[ny][nx] == 0) {
				fire_visit[ny][nx] = fire_visit[cy][cx] + 1;
				fire_que.push({ ny, nx });
			}
		}
	}
}


void man_run() {

	while (!man_que.empty()) {

		pair<int, int> cur = man_que.front();
		man_que.pop();

		int cy = cur.first;
		int cx = cur.second;


		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (IN(ny, nx) && board[ny][nx] != '#' && man_visit[ny][nx] == 0) {
				if (fire_visit[ny][nx] != 0 && man_visit[cy][cx] + 1 >= fire_visit[ny][nx]) continue;
				man_visit[ny][nx] = man_visit[cy][cx] + 1;
				man_que.push({ ny, nx });
			}
		}
	}
}


int main(void) {

	FAST_IO;

	cin >> R >> C;

	board = vector<string>(R, "");
	man_visit = vector<vector<int>>(R, vector<int>(C, 0));
	fire_visit = vector<vector<int>>(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		cin >> board[i];
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				fire_que.push({i, j});
				fire_visit[i][j] = 1;
			}
			if (board[i][j] == 'J') {
				man_que.push({ i, j });
				man_visit[i][j] = 1;
			}
		}
	}

	fire_spread();
	man_run();

	ans = 0x7fffffff;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (man_visit[i][j] > 0 && (i == 0 || i == R - 1 || j == 0 || j == C - 1)) {
				ans = min(ans, man_visit[i][j]);
			}
		}
	}

	if (ans == 0x7fffffff) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";

	return 0;
}
