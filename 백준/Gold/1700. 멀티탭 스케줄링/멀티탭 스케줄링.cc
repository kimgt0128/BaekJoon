#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define F first
#define S second


int N, K, cnt, ans;
pair<int, int> schedule[101];//{item, next_schedule}
int last[101];//마지막 item이 언제 사용되었는지 기록
vector<pair<int, int>> multitab;


int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int item;
		cin >> item;
		schedule[i] = { item, 100000 };
		schedule[last[item]].S = i;
		last[item] = i;
	}

	for (int i = 1; i <= K; i++) {
		//멀티탭의 구멍이 여유로울 때
		auto it = find_if(multitab.begin(), multitab.end(), [&](const pair<int, int>& p) {
			return p.first == schedule[i].first;
			});

		if (cnt < N) {
			if (it != multitab.end()) multitab[it - multitab.begin()] = schedule[i];
			else {
				multitab.push_back(schedule[i]);
				cnt++;
			}
			continue;
		}
		//멀티탭이 모두 채워져 있을 때


		if (it != multitab.end()) {
			multitab[it - multitab.begin()] = schedule[i];
			continue;
		}
		else {
			int remove = 0;
			int time = 0;
			for (int j = 0; j < multitab.size(); j++) {
				int comp = multitab[j].S;
				if (!multitab[j].S || time < comp) {
					remove = j;
					time = comp;
				}
			}
			multitab[remove] = schedule[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}