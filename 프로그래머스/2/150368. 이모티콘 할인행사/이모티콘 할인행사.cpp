#include <string>
#include <vector>

using namespace std;

vector<vector<int>> usr;
vector<int> emo;

vector<int> discount; // A, B, C, D, ...의 할인율을 담은 배열
int num;
int profit;

void dfs() {

    if (discount.size() >= emo.size()) {
    // 플러스 가입자 수 계산 후 비교
        int total = 0;
        int cnt = 0;
        for (int i = 0; i < usr.size(); i++) {
            int cmp_dis = usr[i][0];
            int cmp_mon = usr[i][1];

            int cur_sum = 0;
            for (int j = 0; j < discount.size(); j++) {
                if (discount[j] >= cmp_dis) {
                    cur_sum += emo[j] * (100 - discount[j]) / 100;
                }
            }
            // 멤버의 이모티콘 가격
            if (cur_sum >= cmp_mon) cnt++;
            else total += cur_sum;
        }

        if (cnt > num) {
            num = cnt;
            profit = total;
        }
        else if (cnt == num) profit = max(profit, total);

        return;
    }

    for (int i = 4; i > 0; i--) {
        discount.push_back(10 * i);
        dfs();
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    usr.resize(users.size());
    for (int i = 0; i < users.size(); i++) usr[i] = vector<int>(users[i].begin(), users[i].end());
    emo = vector<int>(emoticons.begin(), emoticons.end());

    dfs();

    vector<int> answer;
    answer.push_back(num);
    answer.push_back(profit);

    return answer;
}