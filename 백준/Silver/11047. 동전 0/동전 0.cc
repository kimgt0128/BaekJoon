#include<iostream>

using namespace std;

int money[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    int idx = 0;
    int ans = 0;

    cin >> N >> K;
    for (idx = 0; idx < N; idx++) cin >> money[idx];

    for (int i = N - 1; i >= 0; i--) {
        ans += K / money[i];
        K %= money[i];

    }
    cout << ans;

    return 0;
}