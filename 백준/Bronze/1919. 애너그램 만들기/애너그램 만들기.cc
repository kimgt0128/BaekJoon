#include<iostream>
//각 단어의 공통 알파벳 수를 샌 다음 제거하기
using namespace std;

string str1, str2;
int alp1[26], alp2[26];
int cnt;

int main(void) {
	cin >> str1 >> str2;

	for (auto e : str1) alp1[e - 'a']++;
	for (auto e : str2) alp2[e - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (alp1[i] == alp2[i]) {
			cnt += alp1[i];
		}
		else cnt += min(alp1[i], alp2[i]);
	}

	cout << str1.size() + str2.size() - 2 * cnt;

	return 0;
}