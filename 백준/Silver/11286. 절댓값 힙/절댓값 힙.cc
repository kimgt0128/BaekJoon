#include <iostream>
#include <queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n;

int main() {
    FAST_IO;

    auto cmp = [](pair<int, char> a, pair<int, char> b) {
        if (a.first != b.first) return a.first > b.first;
        if (a.second == '-' && b.second == '+') return false;
        if (a.second == '+' && b.second == '-') return true;
        return false;
        };
    priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq(cmp);

    cin >> n;

    while (n--) {
        int inp;
        cin >> inp;
        if (inp != 0)
            inp > 0 ? pq.push({ inp, '+' }) : pq.push({ -inp, '-' });
        else {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << (pq.top().second == '+' ? pq.top().first : -pq.top().first) << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
