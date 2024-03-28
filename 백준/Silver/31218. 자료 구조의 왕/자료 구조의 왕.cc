#include<iostream>
#include<algorithm>
#define IN(Y, X) Y > 0 && Y <= N && X > 0 && X <= M
using namespace std;

int N, M, Q;
int cnt;
int map[1001][1001];

void cut(int dy, int dx, int y, int x) {
	if (map[y][x]) return;
	map[y][x] = 1;
	cnt--;
	int cy = y + dy;
	int cx = x + dx;
	while (IN(cy, cx) && !map[cy][cx]) {
		map[cy][cx] = 1;
		cnt--;
		cy += dy;
		cx += dx;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M >> Q;
	cnt = N * M;
	while (Q--) {
		int order;
		cin >> order;
		if (order == 1) {
			int dy, dx, y, x;
			cin >> dy >> dx >> y >> x;
			cut(dy, dx, y, x);
		}
		else if (order == 2) {
			int y, x;
			cin >> y >> x;
			cout << map[y][x] << "\n";
		}
		else {
			cout << cnt << "\n";
		}
	}
	return 0;
}