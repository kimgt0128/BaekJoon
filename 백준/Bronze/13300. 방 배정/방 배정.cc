#include<iostream>

using namespace std;

//성별별로 학년을 저장하기 위한 배열/
int man[7];
int woman[7];
int N, K, S, Y;
int cnt;
int main(void) {
	cin >> N >> K;
	//input
	while (N--) {
		cin >> S >> Y;
		if (S) man[Y]++;
		else woman[Y]++;
	}
	//count: 한 번의 반복문으로 해결해도 됨!
	for (auto e : man) cnt += (e + K - 1) / K;
	for (auto e : woman)cnt += (e + K - 1) / K;

	cout << cnt;
	return 0;
}
