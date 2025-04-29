#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;
int N;
vector<vector<int>> g;
bool visit[200];

void dfs(int k) {
    stack<int> sta;
    visit[k] = 1;
    sta.push(k);

    while (!sta.empty()) {
        int cur = sta.top();
        sta.pop();
        for (int i = 0; i < N; i++) {
            if (!g[cur][i]) continue;
            int nxt = i;
            if (!visit[i]) {
                sta.push(nxt);
                visit[nxt] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    g = vector<vector<int>>(N);

    for (int i = 0; i < N; i++) {
        g[i] = vector<int>(N);
        for (int j = 0; j < n; j++) g[i][j] = computers[i][j];

    }
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            dfs(i);
        }
    }
    return answer;


}
