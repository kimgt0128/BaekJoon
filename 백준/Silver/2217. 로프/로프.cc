#include<iostream>
#include<algorithm>

using namespace std;

int N, ans;
int rope[100000]; 
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> rope[i];
    sort(rope, rope + N);
    for(int i=0; i<N; i++){
        ans = max(ans, rope[i] * (N-i));
    }
    cout << ans;
    return 0;
}