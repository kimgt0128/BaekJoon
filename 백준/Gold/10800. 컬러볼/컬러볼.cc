#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#define F first
#define S second
using namespace std;
typedef long long LL;
LL N, sum;
tuple<LL, LL, LL> balls[200001];
LL sumS[200001];
LL sumC[200001];
vector<pair<LL, LL>> ans;


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;

	for(int i=1; i<=N; i++) {
		LL c, s;
		cin >> c >> s;
		balls[i] = make_tuple(s, c, i);
	}
	sort(balls, balls + N+1);

	//prefix sum
	int befSize = 0;
	int befIdx = 0;
	int answer;
	for (int i = 1; i <= N; i++) {
		LL siz = get<0>(balls[i]);
		LL col = get<1>(balls[i]);
		LL num = get<2>(balls[i]);
		if (siz > befSize) {
			answer = sumS[i - 1] - sumC[col];
			befIdx = i;
			befSize = siz;
		}
		else {
			answer = sumS[i - 1] - sumC[col];
			int idx = i-1;
			while (idx >= befIdx) {
				int color = get<1>(balls[idx]);
				int s = get<0>(balls[idx]);
				if (color != col) answer -= s;
				idx--;
			}
		}
		sumS[i] = sumS[i - 1] + siz;
		sumC[col] += siz;
		ans.push_back({num, answer});
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i].S << "\n";
	return 0;
}
