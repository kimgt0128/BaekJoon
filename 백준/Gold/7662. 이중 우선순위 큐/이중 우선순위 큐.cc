#include<iostream>
#include<map>
#include<queue>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int T, N;
int cnt;
map<int, int> m; // 들어간 값의 개수<dat, cnt>

int main(void) {
	FAST_IO;

	cin >> T;
	while (T--) {
		cin >> N;

		priority_queue<int> max_pq;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		cnt = 0;
		m.clear();
		 
		/** 
		예시
		9
		I -45 -> max_pq = {-45}, min_pq = {-45}, m[-45] = 1, cnt = 1
		I 653 -> max_pq = {-45, 653}, min_pq = {-45, 653}, m[-45] = 1, m[653] = 1, cnt = 2
		D 1 -> max_pq = {-45}, min_pq = {-45, 653(쓰레기)}, m[-45] = 1, m[653] = 0, cnt = 1
		I -642 -> max_pq = {-45, -642}, min_pq = {-45, 653(쓰레기), -642}, m[-45] = 1, m[653] = 0, m[-642] = 1, cnt = 2
		I 45 -> max_pq = {-45, -642, 45}, min_pq = {-45, 653(쓰레기), -642, 45}, m[-45] = 1, m[653] = 0, m[-642] = 1, m]45] = 1,  cnt = 3
		I 97 -> max_pq = {-45, -642, 45, 97}, min_pq = {-45, 653(쓰레기), -642, 45, 97}, m[-45] = 1, m[653] = 0, m[-642] = 1, m]45] = 1, m[97] = 1, cnt = 4
		D 1 -> max_pq = {-45, -642, 45}, min_pq = {-45, 653(쓰레기), -642, 45, 97(쓰레기)}, m[-45] = 1, m[653] = 0, m[-642] = 1, m]45] = 1, m[97] = 0, cnt = 3
		D -1 -> max_pq = {-45, -642(쓰레기), 45}, min_pq = {-45, 653(쓰레기), 45, 97(쓰레기)}, m[-45] = 1, m[653] = 0, m[-642] = 0, m]45] = 1, m[97] = 0, cnt = 2
		I 333 -> max_pq = {-45, -642(쓰레기), 45, 333}, min_pq = {-45, 653(쓰레기), 45, 97(쓰레기), 333}, m[-45] = 1, m[653] = 0, m[-642] = 0, m]45] = 1, m[97] = 0, m[333] = 1, cnt = 3

		이후 마지막에 max_pq에서 m[top] == 0이면 다제거하고, 0이 아닌 최초값 가져옴
		마찬가지로 min_pq에서 m[top] == 0 이면 다 제거하고, 0이 아닌 최초값 가져옴
		**/
		while (N--) {

			char ord;
			int dat;

			cin >> ord >> dat;

			if (ord == 'I') {
				max_pq.push(dat);
				min_pq.push(dat);
				cnt++;
				m[dat]++;
			}
			else {
				if (cnt == 0) continue; // 비어있으면 무시
				// 값 제거 후 각각 동기화
				int tmp;
				if (dat == 1) {
					while (!max_pq.empty() && m[max_pq.top()] == 0) max_pq.pop();
					tmp = max_pq.top();
					max_pq.pop();
				}
				else {
					while (!min_pq.empty() && m[min_pq.top()] == 0) min_pq.pop();
					tmp = min_pq.top();
					min_pq.pop();
				}
				cnt--;
				m[tmp]--;
			}
			//cout << "cnt: " << cnt << ", max_heap_siz: " << max_pq.size() << ", min_heap_siz: " << min_pq.size() << endl;
		}

		while (!max_pq.empty() && m[max_pq.top()] == 0) max_pq.pop();
		while (!min_pq.empty() && m[min_pq.top()] == 0) min_pq.pop();

		//cout << "최종: cnt: " << cnt << ", max_heap_siz: " << max_pq.size() << ", min_heap_siz: " << min_pq.size() << endl;
		if (cnt == 0) cout << "EMPTY\n";
		else {
			cout << max_pq.top() << ' ' << min_pq.top() << '\n';
		}
	}
}
