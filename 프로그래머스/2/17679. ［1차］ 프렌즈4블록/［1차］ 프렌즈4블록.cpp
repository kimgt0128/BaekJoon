#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

char mp[30][30];
int M, N;
int dy[3] = { 1, 0, 1 }; // 크기 3으로 수정
int dx[3] = { 0, 1, 1 }; // 크기 3으로 수정

set<pair<int, int>> s;

bool check(int cy, int cx) {
    char cmp = mp[cy][cx];
    for (int i = 0; i < 3; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (mp[ny][nx] != cmp) return false;
    }
    return true;
}


int solve() {
    int ans = 0;

    while (true) {
        bool flag = false;

        // 지울 좌표 set에 추가
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mp[i][j] == 'X') continue;
                int cy = i;
                int cx = j;
                
                if (i <= M - 2 && j <= N - 2 && check(cy, cx)) {
                    flag = true;
                    s.insert({ cy, cx });
                    s.insert({ cy + 1, cx });
                    s.insert({ cy, cx + 1 });
                    s.insert({ cy + 1, cx + 1 });
                }
            }
        }

        if (!flag) break;

        //지우기
        while (!s.empty()) {
            pair<int, int> cor = *s.begin();
            mp[cor.first][cor.second] = 'X';
            ans++;
            s.erase(s.begin());
        }
        // 아래로 밀기        
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (mp[i][j] == 'X') {
                    int k = i;

                    // 상단의 값 찾기
                    while (k >= 0 && mp[k][j] == 'X') {
                        k--;
                    }

                    // 값 바꾸기
                    if (k >= 0) {
                        mp[i][j] = mp[k][j];
                        mp[k][j] = 'X';
                    }

                }
            }
        }


    }
    return ans;

}



int solution(int m, int n, vector<string> board) {
    M = board.size();
    N = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mp[i][j] = board[i][j];
        }
    }
    int answer = solve();
    return answer;
}


int main(void) {

    M = 6;
    N = 6;
    vector<string> brd;
    brd = vector<string>(N);
    for (int i=0; i < N; i++) {
        cin >> brd[i];
    }

    cout << solution(M, N, brd);

}