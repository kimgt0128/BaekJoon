#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<int> q;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int head;
	int tail;
	cin >> n;
	for (int i = 0; i < n; i++) q.push(i + 1);
	while (q.size() != 1){
		q.pop();
		head = q.front();
		q.pop();
		q.push(head);
		//cout << q.front() << "\n";
	}
	cout << q.front();

	return 0;
}