#include<iostream>
#include<cstring>

using namespace std;

string cmp1, cmp2;
int cnt1[26], cnt2[26];
bool possible = true;

int main(void) {
	int N;
	cin >> N;
	while (N--) {
		possible = true;
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		cin >> cmp1 >> cmp2;
	
		for (int i = 0; i < cmp1.size(); i++) {
			cnt1[cmp1[i] - 'a']++;
			cnt2[cmp2[i] - 'a']++;
			
		}

		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
				possible = false;
				break;
			}
		}

		if (possible) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
	return 0;
}