#include<iostream>
#include<queue>
#define F first
#define S second
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;
typedef pair<int, int> PII;

int n;
int adj[1001][1001];
priority_queue<PII, vector<PII>, greater<PII>> pq;
bool visit[1001];


long long prim(int start) {

	long long weight = 0;
	pq.push({0, start});
	

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();
		if (visit[cur.S]) continue;
		visit[cur.S] = true;
		weight += cur.F;
		for (int i = 1; i < n + 1; i++) {
			if (visit[i] || !adj[cur.S][i])continue;
			pq.push({adj[cur.S][i], i});
		}
	}
	return weight;

}

int main(void) {
	FAST_IO;
	
	cin >> n;


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> adj[i][j];
		}
	}
	cout << prim(1);

	return 0;
}