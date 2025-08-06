#include<iostream>
#include<map>
#include<vector>
#include<queue>
#define IN(Y, X) (Y >= 0 && Y < n && X >=0 && X < n)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int n;
vector<vector<int>> board;
vector<vector<bool>> visit;
map<pair<int, int>, int> fishes; // 남은 물고기들(y, x)
pair<int, int> pos;
int siz = 2;
int cnt, ans;


priority_queue<tuple<int, int, int>, 
	vector<tuple<int, int, int>>, 
	greater<tuple<int, int, int>>> pq;
queue<pair<int, int>> que;

void bfs(int y, int x) {
	que.push({ y, x });
	visit[y][x] = true;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		int cy = cur.first;
		int cx = cur.second;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (IN(ny, nx) && !visit[ny][nx]) {
				que.push({ ny, nx });
				visit[ny][nx] = true;
				board[ny][nx] = board[cy][cx] + 1;
			}
		}
	}
}


int main(void) {

	FAST_IO;

	cin >> n;
	board = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 9) pos = { i, j };
			else if (x == 0) continue;
			else fishes[{i, j}] = x;
		}
	}


	while (true) {
		// board 비우기
		board = vector<vector<int>>(n, vector<int>(n, 0));
		visit = vector<vector<bool>>(n, vector<bool>(n, false));
		vector<pair<int, int>> eat;
		while (!pq.empty()) pq.pop();

		// 가능 물고기 찾기
		for (auto f : fishes) {
			// 못먹으면 방문하지 않도록
			if (siz < f.second)	visit[f.first.first][f.first.second] = true;
			
			// 먹을 수 있는 물고기 표시
			if (siz > f.second) {
				eat.push_back({ f.first.first, f.first.second });
			}
		}
		// 먹을 수 있는 물고기가 없으면 종료
		if (eat.size() == 0) break;
		// BFS
		bfs(pos.first, pos.second);
			
		for (auto f : eat) {
			if (visit[f.first][f.second]) pq.push(make_tuple(board[f.first][f.second], f.first, f.second));
		}

		if (pq.empty()) break;
		// 이동하며 시간 증가
		ans += get<0>(pq.top());
		// 아기상어 크기 증가
		
		cnt++;
		if (cnt == siz) {
			siz++;
			cnt = 0;
		}
		// 아기 상어 위치 갱신
		pos = { get<1>(pq.top()), get<2>(pq.top()) };
		// map에서 먹은 물고기 제거
		fishes.erase({ get<1>(pq.top()), get<2>(pq.top()) });

		eat.clear();

	}

	cout << ans;
	return 0;

}