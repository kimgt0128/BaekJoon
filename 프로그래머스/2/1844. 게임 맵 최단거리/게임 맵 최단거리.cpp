#include<iostream>
#include<queue>
#include<vector>
#define IN(Y, X) (Y < N && Y >= 0 && X < M && X >= 0)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define F first
#define S second
using namespace std;
typedef pair<int, int> PII;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool visit[100][100];
queue<PII> que;



int solution(vector<vector<int>> maps) {
	int answer = -1;
    
    int N = maps.size();
    int M = maps[0].size();

	que.push({ 0, 0 });
	visit[0][0] = true;

	while (!que.empty()) {
		PII cur = que.front();
		que.pop();
		int cy = cur.F;
		int cx = cur.S;

		if (cy == N - 1 && cx == M - 1) return maps[cy][cx];

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (IN(ny, nx) && maps[ny][nx] == 1 && !visit[ny][nx]) {
				maps[ny][nx] = maps[cy][cx] + 1; // cnt 
				visit[ny][nx] = true;
				que.push({ ny, nx });
			}
		}
	}
	return answer;
}