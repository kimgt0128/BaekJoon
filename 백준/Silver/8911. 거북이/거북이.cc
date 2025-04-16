#include<iostream>

using namespace std;

int n;
string order;

int dir; // 북 동 남 서 :  0, 1, 2, 3
int mn, ms, mw, me; //현재까지 최대 방향
int cy, cx; // 현재 좌표
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	

	while (n--) {
		cin >> order;
		mn = ms = mw = me = 0;
		cy = cx = 0;
		dir = 0;

		// 1. 방향을 바꾸는 경우 R(1), L(-1)
		// 2. 앞뒤로 가는 경우
		
		for (auto e : order) {
			if (e == 'F' || e == 'B') {
				int d = (e == 'F' ? 1 : -1);
				if (dir == 0) {
					cy += 1 * d;
					mn = max(cy, mn);
					ms = min(cy, ms);
				}
				else if (dir == 1) {
					cx += 1 * d;
					me = max(me, cx);
					mw = min(mw, cx);
				}
				else if (dir == 2) {
					cy+= (-1) * d;
					ms = min(ms, cy);
					mn = max(mn, cy);
				} else { // dir == 3
					cx += (-1) * d;
					mw = min(mw, cx);
					me = max(me, cx);
				}
			} else { // R L인 경우
				e == 'R' ? dir++ : (dir += 3);
				dir %= 4;
			}
		}
		cout << (me - mw) * (mn - ms) << "\n";
	}
	return 0;
}