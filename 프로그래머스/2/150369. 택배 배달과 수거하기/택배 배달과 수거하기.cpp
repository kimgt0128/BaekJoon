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
            answer += 2 * (tmp+1);
            tmp = idx;
            deliveries[idx] = -del;
            pickups[idx] = -pic;
            del = cap;
            pic = cap;
        }
    }
    if(del < cap || pic < cap ) answer += 2 * (tmp+1);

    return answer;
}