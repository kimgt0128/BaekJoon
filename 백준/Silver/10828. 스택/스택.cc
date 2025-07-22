#include<iostream>
#include<vector>

using namespace std;

vector<int> stack;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		string order;
		cin >> order;

		if (order == "pop") {
			if (stack.empty()) cout << -1 << "\n";
			else {
				cout << stack.back() << "\n";
				stack.pop_back();
			}
		}

		else if (order == "size") {
			cout << stack.size() << "\n";
		}
		else if (order == "empty") {
			cout << stack.empty() << "\n";
		}

		else if(order == "top") {
			if (stack.empty()) cout << -1 << "\n";
			else cout << stack.back() << "\n";
		}

		else {
			int x;
			cin >> x;
			stack.push_back(x);
		}
	}
}