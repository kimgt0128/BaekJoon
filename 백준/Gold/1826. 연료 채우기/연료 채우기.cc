#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> stations;
priority_queue<pair<int, int>> pq; // fuel, distance
int n;
int ans;

int main(void) {
	FAST_IO;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b; // a: distance, b: fuel
		stations.push_back({ a, b });		
	}
	int L, P;
	cin >> L >> P;

	// Greedy Solution
	sort(stations.begin(), stations.end());

	int idx = 0;
	while(P < L) {

		// 모든 주유소를 지나지 않은 경우
		if (idx < n) {
			// 가능 거리보다 가까운 주유소: 저장
			if (P >= stations[idx].first) {
				pq.push({ stations[idx].second, stations[idx].first });
				idx++;
			}
			// 가능 거리보다 먼 주유소: 주유 후 주유소 저장
			else {
				if (pq.empty()) break; // 전의 주유소에서 모두 주유해도 갈 수 없는 경우
				pair<int, int> stop = pq.top();
				pq.pop();
				P += stop.first; // 주유하기
				ans++;
			}
		}

		// 주유소를 모두 지난 경우
		else {
			if (pq.empty()) break;
			pair<int, int> stop = pq.top();
			pq.pop();
			
			P += stop.first;
			ans++;
		}

	}

	if (P >= L) cout << ans;
	else cout << -1;



	

	
}