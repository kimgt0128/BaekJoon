#include<iostream>
#include<cstring>

using namespace std;

string cmp1, cmp2;
int cnt[26];
bool possible = true;

int main(void) {
	int N;
	cin >> N;
	while (N--) {
		possible = true;
		memset(cnt, 0, sizeof(cnt));
		cin >> cmp1 >> cmp2;
	
		for (int i = 0; i < cmp1.size(); i++) {
			cnt[cmp1[i] - 'a']++;
			cnt[cmp2[i] - 'a']--;
			
		}

		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				possible = false;
				break;
			}
		}

		if (possible) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
	return 0;
}