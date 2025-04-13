#include<iostream>
#include<queue>
using namespace std;

int ans;
int solution(vector<int> scovile, int k) {
	priority_queue<int, vector<int>, greater<int>> mpq(scovile.begin(), scovile.end(), greater<int>());
	
	while (mpq.top() < k && mpq.size() >= 2) {

		int m1 = mpq.top();
		mpq.pop();
		int m2 = mpq.top();
		mpq.pop();

		int x = m1 + m2 * 2;
		mpq.push(x);
		ans++;
	}
	if (mpq.top() < k) return -1;
	return ans;
}