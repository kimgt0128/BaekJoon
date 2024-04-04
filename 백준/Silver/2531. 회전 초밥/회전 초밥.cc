#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, d, k, c, ans, cnt;
int dish[3001];
queue<int> susi;


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> d >> k >> c;
	vector<int> v(N, 0);
	for (int i = 0; i < v.size(); i++) cin >> v[i];
	for (int i = 0; i < k-1; i++) v.push_back(v[i]);
	for (int i = 0; i < v.size(); i++) {
		int val = v[i];
		if (susi.size() == k) {
			int front = susi.front();
			if (dish[front] == 1) cnt--;
			dish[front]--;
			susi.pop();
		}
		//push
		if (!dish[val])	cnt++;
		susi.push(val);
		dish[val]++;

		//최대 갱신
		if (!dish[c]) ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}