#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
string s;
vector<string> a;
bool dp[101];
int main(void) {
	FAST_IO;


	cin >> s >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	dp[0] = true;
	for (int i = 0; i < s.size(); i++) {
		int cur_idx = i + 1;
		for (int j = 0; j <=i; j++) {
			int cmp_idx = j + 1;
			int cmp_len = i - j + 1;
			if (dp[i + 1]) break;
			for (int k = 0; k < a.size(); k++) {
				// 길이가 맞지 않으면 pass
				if (a[k].size() != cmp_len)continue;
				// 이전까지 만들 수 없으면 pass
				if (dp[cur_idx - a[k].size()] == false) continue;
				if (a[k] == s.substr(cur_idx - a[k].size(), a[k].size())) {
					dp[i + 1] = true;
					break;
				}

			}
		}
	}

	cout << dp[s.size()];

}