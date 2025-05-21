#include<iostream>
#include<set>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int T, N;
multiset<int> ms;
int main(void) {
	FAST_IO;

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			char order;
			int dat;
			cin >> order >> dat;
			if (order == 'I') ms.insert(dat);
			else {
				if (ms.empty()) continue;
				if (dat == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else {
			auto min_it = *ms.begin();
			auto max_it = prev(ms.end());

			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
		ms.clear();
	}


}