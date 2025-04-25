#include <string>
#include<iostream>
#include <vector>
#include <cmath>
/** 단조스택을 이용한 풀이
        1. 스택 내림차순 유지
        2. 단조스택 유지하다가 스택이 비면 모두 계산하기
    예를 들어, 배포일이{5 10 2 1 3 4 99 1 2 3 }인 경우
        sta: 5(sta이 비어있을 때, cnt = 0이면 예외이므로 넘기기)
        sta: 10(5 제거, cnt = 1, 5가 들어가기 전 sta이 비어있으므로 1개 처리)
        sta: 10, 2, 1
        sta: 10, 3(2, 1제거, cnt = 2)
        sta: 10, 4(3 제거, cnt = 3)
        sta: 99(4, 10 제거, cnt = 5, 300이 들어가기 전 sta이 비어있으므로 제거한 5개 처리)
        sta: 99, 1
        sta: 99, 2(1 제거, cnt = 1)
        sta: 99, 3(2 제거, cnt = 2)
        마지막에 강제로 sta에 100 추가: 3, 99 제거, cnt = 4
        따라서 정답은 1, 5, 4
**/
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> launch;
    vector<int> sta;
    for (int i = 0; i <= progresses.size(); i++) {
        //마지막에 강제로 100일을 추가하여 마지막 작업까지 배포되도록 하기
        if (i == progresses.size()) {

            launch.push_back(100);
            continue;
        }
        // 마감까지 남은 일수 계산
        int pro = progresses[i];
        int spe = speeds[i];
        int day = ceil(static_cast<double>(100 - pro) / spe);
        launch.push_back(day);
    }
    int cnt = 0;
    for (auto e : launch) {
        int cur = e;
        while (!sta.empty() && cur > sta.back()) {
            sta.pop_back();
            cnt++;
        }
        if (sta.empty() && cnt != 0) {
            answer.push_back(cnt);
            cnt = 0;
        }
        sta.push_back(cur);
    }
    return answer;
}