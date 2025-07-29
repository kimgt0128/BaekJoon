#include <string>
#include<sstream>
#include <vector>
#include<map>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

map<char, int> trm;

int convert_to_days(string date) {
    int ret = 0;
    replace(date.begin(), date.end(), '.', ' ');
    istringstream iss(date);
    int year, month, day;

    iss >> year >> month >> day;
    
    ret += (year * 12 * 28) + (month * 28) + day;
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // 오늘 날짜 일수로 저장
    int cmp_today = convert_to_days(today);

    // map에 약관 기한 저장
    for (auto data : terms) {
        istringstream iss(data);
        char name;
        int month;
        iss >> name >> month;
        trm[name] = month;
    }

    for (int i = 0; i < privacies.size(); i++) {
        istringstream iss(privacies[i]);
        char name;
        string start_date;
        iss >> start_date >> name;

        int exp_days = convert_to_days(start_date) + (28 * trm[name]);

        if (exp_days <= cmp_today) answer.push_back(i + 1);
    }

    return answer;
}