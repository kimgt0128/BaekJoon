#include<iostream>
#include<set>
#include<string>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int T, N;
multiset<int> ms;

vector<int> solution(vector<string> operations) {
	FAST_IO;
	vector<int> ans;
	for (auto e : operations) {
		int spaceItr = e.find(' ');
		string order = e.substr(0, spaceItr);
		int dat = stoi(e.substr(spaceItr + 1));

		if (order == "I") ms.insert(dat);
		else {
			if (ms.empty()) continue;
			if (dat == 1) ms.erase(prev(ms.end()));
			else ms.erase(ms.begin());
		}
	}
	if (ms.empty()) ans.push_back(0), ans.push_back(0);
	else ans.push_back(*prev(ms.end())), ans.push_back(*ms.begin());
	return ans;
}
