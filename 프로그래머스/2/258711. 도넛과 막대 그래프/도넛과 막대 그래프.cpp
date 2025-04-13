#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> cnt(1000001);
bool visit[1000001];
vector<vector<int>> adj;
vector<int> ans(4);


void dfs(int start) {
	int flag = 0;
	stack<int> sta;
	sta.push(start);
	while (!sta.empty()) {
		int cur = sta.top();
		if (visit[cur] != 0) flag++;
		visit[cur] = true;
		sta.pop();

		while (!adj[cur].empty()) {
			int nxt = adj[cur].back();
			sta.push(nxt);
			adj[cur].pop_back();
		}
	}
	if (flag == 2) ans[3]++;
	else if (flag == 1) ans[1]++;
	else if (flag == 0) ans[2]++;
}

vector<int> solution(vector<vector<int>> edges) {
	// 그래프 구조 변환 간선 리스트 -> 인접 리스트
	int maxNode = 0;
	for (auto e : edges) {
		maxNode = max(maxNode, max(e[0], e[1]));
	}
	adj.resize(maxNode + 1);

	
	// 정점마다 들어오는 간선 개수 미리 저장해놓기
	for (auto e : edges) {
		int u = e[0];
		int v = e[1];
		adj[u].push_back(v);
		cnt[v]++;
	}
	int node;
	// 외부 노드 찾기
	for (int i = 1; i <= adj.size(); i++) {
		if (cnt[i] == 0 && adj[i].size() >= 2) {
			node = i;
			ans[0] = node;
			break;
		}
	}

	// 탐색
	for (auto e: adj[node]) {
		dfs(e);
	}
	return ans;
}

int main() {
	vector<vector<int>> g(13);
	
	for (int i = 0; i <= 12; i++) {

	}
	return 0;
}