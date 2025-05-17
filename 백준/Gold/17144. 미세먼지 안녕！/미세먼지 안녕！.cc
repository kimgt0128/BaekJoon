#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define F first
#define S second
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) ((Y >= 0 && Y < R) && (X >= 0 && X < C))
typedef pair<int, int> PII;

int R, C, T;
int board[50][50];
int cnt[50][50]; // i, j에서 확산한 공간의 개수를 저장하는 배열
int tmp[50][50];
vector<PII> purifilter;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void diffusion() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 공기청정기 or 먼지가 없으면 pass
			if (board[i][j] == 0 || board[i][j] == -1) continue;
			int dust = board[i][j];
			int spread = dust / 5;
			// i, j기준으로 상하좌우 탐색
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				// 상하좌우가 공기청정기가 아니고 범위 안에 있으면 먼지 전처리(임시 저장)
				if (IN(ny, nx) && board[ny][nx] != -1) {
					tmp[ny][nx] += spread;
					cnt[i][j]++;
				}
			}
		}
	}
	//임시 저장된 먼지를 처리하여 먼지 퍼뜨리기 후처리(임시 저장된 먼지들 반영)
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//먼지가 퍼진 후 현재 칸의 먼지 = 원래 먼지 - 사방으로 퍼진 양 + 다른 칸에서 퍼진 먼지양
			int spreaded = board[i][j] / 5;
			board[i][j] = board[i][j] - cnt[i][j] * spreaded + tmp[i][j];
		}
	}
	// 다음 사용을 위해 tmp 배열 초기화
	memset(tmp, 0, sizeof(tmp));
	memset(cnt, 0, sizeof(cnt));
}

void purification(int a, int b) {
	int last; // 밀 때마다 마지막 남은 하나
	//첫 번재 순환
	//가로1: 공기 청정기 첫 번째 가로 밀고 마지막 값 last에 가져오기
	vector<int> line1 = vector<int>(C, 0);
	copy(board[a] + 1, board[a] + C - 1, line1.begin() + 1);//임시로 line을 만들고
	last = board[a][C - 1];//마지막 값을 임시저장한 후
	copy(line1.begin(), line1.end(), &board[a][1]); // 밀어버리기

	//세로1: 
	int tmp1, pre;
	pre = last;
	for (int i = a-1; i >= 0; i--) {
		tmp1 = board[i][C-1];
		board[i][C-1] = pre;
		pre = tmp1;
	}
	last = pre;

	// 가로2:
	vector<int> line2 = vector<int>(board[0] + 1, board[0] + C -1);
	line2.push_back(last);
	last = board[0][0];
	copy(line2.begin(), line2.end(), board[0]);

	//세로2(공기 청정기 행)
	pre = last;
	for (int i = 1; i < a; i++) {
		tmp1 = board[i][0];
		board[i][0] = pre;
		pre = tmp1;
	}

	// 두 번째 순환
	last = board[b][C - 1];
	vector<int> line3 = vector<int>(C, 0);
	copy(board[b] + 1, board[b] + C - 1, line3.begin() + 1);
	copy(line3.begin(), line3.end(), board[b] + 1);
	
	
	pre = last;
	for (int i = b+1; i < R; i++) {
		tmp1 = board[i][C - 1];
		board[i][C - 1] = pre;
		pre = tmp1;
	}
	last = pre;

	vector<int> line4 = vector<int>(board[R-1] + 1, board[R-1] + C - 1);
	line4.push_back(last);
	last = board[R - 1][0];
	copy(line4.begin(), line4.end(), board[R - 1]);

	pre = last;
	for (int i = R - 2; i > b; i--) {
		tmp1 = board[i][0];
		board[i][0] = pre;
		pre = tmp1;
	}
}


int getDust() {
	int ret = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != -1) ret += board[i][j];
		}
	}
	return ret;
}
int solve() {
	// 어차피 미세먼지가 퍼져도, 전체 미세먼지의 양은 변하지 않는다.
	// 미세먼지는 오직 공기청정기에 들어갈 때이다.
	int ans = 0;
	while (T--) {
		// 1. 미세먼지 확산
		diffusion();

		// 2. 공기청적기 작동
		purification(purifilter[0].F, purifilter[1].F);

		ans = getDust();
	}
	return ans;
}
int main(void) {
	FAST_IO;
	
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) purifilter.push_back({i, j});
		}
	}
	cout << solve();
	return 0;
}