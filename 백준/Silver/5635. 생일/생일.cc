#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

string str;
int n;
map<tuple<int, int, int>, string> birth;


int main(void) {
	FAST_IO;
	cin >> n;
	cin.ignore();

	while (n--) {
		string str, name;
		int day, month, year;

		getline(cin, str);
		istringstream iss(str);
		iss >> name >> day >> month >> year;

		birth[{year, month, day}] = name;

	}

	auto yung = birth.rbegin();
	auto old = birth.begin();
	cout << yung->second << "\n" << old->second;

	return 0;
}

