#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y >= 0 && Y < H && X >= 0 && X < W)
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int T, H, W, ans;
vector<string> board;
vector<vector<int>> fire_visit;
vector<vector<int>> man_visit;
queue<pair<int, int>> fire_que;
queue<pair<int, int>> man_que;


void fire_bfs() {

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
				board[ny][nx] = '*';
				fire_que.push({ ny, nx });
			}
		}
	}
}

void man_bfs() {

	while (!man_que.empty()) {
		pair<int, int> cur = man_que.front();
		man_que.pop();
		int cy = cur.first;
		int cx = cur.second;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (!IN(ny, nx)) {
				ans = man_visit[cy][cx];
				return;
			}

			if (board[ny][nx] != '#' && man_visit[ny][nx] == 0) {
				if (fire_visit[ny][nx] != 0 && man_visit[cy][cx] + 1 >= fire_visit[ny][nx]) continue;
				board[ny][nx] = '@';
				man_visit[ny][nx] = man_visit[cy][cx] + 1;
				man_que.push({ ny, nx });
			}
		}
	}
}



int main(void) {
	FAST_IO;

	cin >> T;
	while (T--) {
		cin >> W >> H;

		board = vector<string>(H, "");
		fire_visit = vector<vector<int>>(H, vector<int>(W, 0));
		man_visit = vector<vector<int>>(H, vector<int>(W, 0));
		ans = 0;
		while (!fire_que.empty()) fire_que.pop();
		while (!man_que.empty()) man_que.pop();


		for (int i = 0; i < H; i++) {
			cin >> board[i];
			for (int j = 0; j < W; j++) {
				// 상근이와 불만 미리 기록하기
				if (board[i][j] == '*') {
					fire_visit[i][j] = 1;
					fire_que.push({ i, j });
				}
				if (board[i][j] == '@') {
					man_que.push({ i, j });
					man_visit[i][j] = 1;
				}
			}
		}

		fire_bfs();
		man_bfs();


		if (ans) cout << ans << "\n";
		else cout << "IMPOSSIBLE\n";
		
	}

	return 0;
}

