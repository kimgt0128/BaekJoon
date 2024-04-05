#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int contry[101];
tuple<int, int, int> students[101];
vector<pair<int, int>> ans;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, n, s;
		cin >> c >> n >> s;
		students[i] = make_tuple(s, n, c);
	}
	sort(students, students + N, greater<tuple<int, int, int>>());
	for (int i = 0; i < N; i++) {
		int score = get<0>(students[i]);
		int num = get<1>(students[i]);
		int con = get<2>(students[i]);
		if (ans.size() == 3) break;
		if (contry[con] == 2) continue;
		contry[con]++;
		ans.push_back({ con, num });
	}
	for (auto e : ans) cout << e.first << " " << e.second << "\n";
}