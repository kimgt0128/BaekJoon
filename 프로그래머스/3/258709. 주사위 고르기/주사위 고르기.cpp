#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
vector<vector<int>> dic;
vector<int> comb_a;
vector<int> comb_b;
vector<int> sum_b;
vector<int> sum_a;
vector<int> ans; // 최대 승리 조합
int max_win = -1;

void dekart_sum(vector<int> comb, vector<int>& sum) {
    sum.clear();
    int siz = comb.size();
    
    vector<int> indice(siz, 0);

    while (true) {
        int total = 0;
        for (int i = 0; i < siz; i++) {
            total += dic[comb[i]][indice[i]];
        }
        sum.push_back(total);


        int k = siz - 1;
        while (k >= 0) {
            indice[k]++;
            if (indice[k] < dic[comb[k]].size()) break;
            indice[k] = 0;
            k--;
        }
        if (k < 0) break;
    }
}



void probablity() {
    comb_b.clear();
    // 나머지로 B가 고른 조합 만들기
    for (int i = 0; i < dic.size(); i++) {
        if (find(comb_a.begin(), comb_a.end(), i) == comb_a.end()) {
            comb_b.push_back(i);
        }
    }

    // 데카르트 곱으로 모든 주사위 조합의 합 만들기

    dekart_sum(comb_a, sum_a);
    dekart_sum(comb_b, sum_b);

    
    // 이분 탐색으로 a가 이길 경우의 수 배열
    int win = 0;
    sort(sum_a.begin(), sum_a.end());
    sort(sum_b.begin(), sum_b.end());

    for (int cur : sum_a) {
        auto it = lower_bound(sum_b.begin(), sum_b.end(), cur);
        win += (it - sum_b.begin());
    }


    // 최대 승리 조합 저장
    if (win > max_win) {
        max_win = win;
        ans = comb_a;
    }

 
    sum_a.clear();
    sum_b.clear();
}


void solve(int depth, int idx) {
    if (depth == K) {
        // 확률 계산하기
        probablity();
        return;
    }

    // 재귀적으로 조합 만들기
    for (int i = idx; i < dic.size(); i++) {
        comb_a.push_back(i);
        solve(depth+1, i + 1);
        comb_a.pop_back();
    }
}




vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;

    N = dice.size();
    K = N / 2;

    dic.resize(N);
    for (int i = 0; i < dice.size(); i++) {
        // dice 를 dic에 복사
        dic[i] = vector<int>(dice[i].begin(), dice[i].end());
    }

    solve(0, 0);

    for (int e : ans) answer.push_back(e + 1);

    return answer;
}

int main() {
    // 예시 입력: 4개의 주사위
    vector<vector<int>> dice = {
        {40, 41, 42, 43, 44, 45},
        {43, 43, 42, 42, 41, 41},
        {1, 1, 80, 80, 80, 80},
        {70, 70, 1, 1, 70, 70}
    };
    // solution 함수 호출
    vector<int> result = solution(dice);

    // 결과 출력
    cout << "A가 선택해야 할 주사위 번호(1-based): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // 디버깅용: 승리 조합과 승리 확률 출력
    extern int max_win; // 전역 변수 사용
    cout << "A의 최대 승리 경우의 수: " << max_win << endl;
}