#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define F first
#define S second
using namespace std;
typedef pair<int, int> PII;

int n;
vector<PII> dat;
stack<int> sta;



int main(void) {
	FAST_IO;
	cin >> n;

	
	// 4 -> 3 5 2 7
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		dat.push_back({ cur, -1 }); // 값, 현재 index로 저장
			
		while (!sta.empty() && dat[sta.top()].F < cur) {
			dat[sta.top()].S = cur;
			sta.pop();
		}
		sta.push(i);
	}

	for (int i = 0; i < n; i++) cout << dat[i].S << " ";
	return 0;
}