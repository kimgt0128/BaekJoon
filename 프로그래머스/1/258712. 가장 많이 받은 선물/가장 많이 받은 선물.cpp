#include <string>
#include<cstring>
#include <vector>
#include <map>
#include<sstream>
#include<algorithm>

using namespace std;

map<string, map<string, int>> record; //a 가 b에게 선물을 몇개 주었는지 기록
map<string, int> score; // 선물 지수 기록
map<string, int> cnt; // 받을 선물의 개수 기록하는 map




int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for (string str : gifts) {
        istringstream iss(str);
        string tmp, a, b;
        int idx = 0;
 
        iss >> a >> b;
        record[a][b]++;
        score[a]++;
        score[b]--;

    }

    // 친구 조합을 순회하며 받는 선물 개수 세기
    for (int i = 0; i < friends.size()-1; i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            // 조합별로 선물을 받을사람, 주는사람 기록
            string a = friends[i];
            string b = friends[j];
            // 두 사람이 선물을 주고받은 기록이 존재하는 경우
            if (record[a].count(b) || record[b].count(a)) {
                if (record[a][b] > record[b][a]) cnt[a]++;
                else if (record[a][b] < record[b][a]) cnt[b]++;
                else {
                    if (score[a] > score[b]) cnt[a]++;
                    else if (score[a] < score[b]) cnt[b]++;
                }
            }
            else {
                if (score[a] > score[b]) cnt[a]++;
                else if (score[a] < score[b]) cnt[b]++;
            }
        }
    }

    if (cnt.size()) {

        answer = max_element(
            cnt.begin(), cnt.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second < b.second;
            }
        )->second;
    }
    else {
        answer = 0;
    }




    return answer;
}