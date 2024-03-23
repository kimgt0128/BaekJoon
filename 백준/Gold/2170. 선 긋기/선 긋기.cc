#include<iostream>
#include<algorithm>
#define F first
#define S second

using namespace std;

long long int N, ans;
pair<int, int> line[1000000];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		line[i] = { x, y };
	}
	//solve
	sort(line, line + N);
	int en = -1000000001;
	for (int i = 0; i < N; i++) {
		if (line[i].F > en) {
			ans += line[i].S - line[i].F;
			en = line[i].S;
		}
		else{
			if (line[i].S > en) {
				ans += line[i].S - en;
				en = line[i].S;
			}
		}
	}
	cout << ans;

}