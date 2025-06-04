#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


int n, k;
int cnt;
vector<int> result;

void backTracking(int num) {
    if (num < 0) return;
	if (num == 0) {
		cnt++;
		return;
	}
    
	for (int i = 1; i < 4; i++) {
		result.push_back(i);
		backTracking(num-i);
		if (cnt == k) return;
		result.pop_back();
	}
}

int main(void) {
	FAST_IO;
	
	cin >> n >> k;

	backTracking(n);

	if (result.empty()) cout << -1;
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
			if (i != result.size() - 1) cout << "+";
		}
	}

	return 0;
}