#include<iostream>
#include<vector>
#include<queue>
#define IN(X) (X >= 0 && X <= 100000)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

vector<int> board(100001, -1);
int N, K, ans;
queue<int> que;

int main(void) {
	FAST_IO;

	cin >> N >> K;

	que.push(N);
	board[N] = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (IN(cur-1) && board[cur - 1] == -1) {
			que.push(cur - 1);
			board[cur - 1] = board[cur] + 1;
		}
		if (IN(cur + 1) && board[cur + 1] == -1) {
			que.push(cur + 1);
			board[cur + 1] = board[cur] + 1;
		}
		if (IN(cur * 2) && board[cur * 2] == -1) {
			que.push(cur * 2);
			board[cur * 2] = board[cur] + 1;
		}
	}

	cout << board[K];

	return 0;
}