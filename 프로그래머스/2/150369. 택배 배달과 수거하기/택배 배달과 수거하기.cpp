#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int idx = n - 1;
    int tmp = n - 1;
    int del = cap;
    int pic = cap;
    while(idx >= 0) {

        del -= deliveries[idx];
        pic -= pickups[idx];

        if (del >= 0 && pic >= 0) idx--;
        else {
            answer += 2LL * (tmp+1);  // 꼭 long long 곱 연산!
            tmp = idx;
            deliveries[idx] = -del;
            pickups[idx] = -pic;
            del = cap;
            pic = cap;
        }
    }

    // 마지막 루프에서 else로 빠지지 않았다면, 이동이 필요하므로 한 번 더 거리 추가
    if (del < cap || pic < cap) {
        answer += 2LL * (tmp+1);
    }

    return answer;
}
